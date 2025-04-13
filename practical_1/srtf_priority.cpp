#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid, arrival, burst, remaining, priority, start = -1, completion;
    int response, turnaround, waiting;
    bool is_completed = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Arrival, Burst and Priority for P" << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst >> p[i].priority;
        p[i].remaining = p[i].burst;
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1, min_priority = 1e9, min_remain = 1e9;

        for (int i = 0; i < n; ++i) {
            if (!p[i].is_completed && p[i].arrival <= current_time) {
                if (p[i].priority < min_priority ||
                    (p[i].priority == min_priority && p[i].remaining < min_remain)) {
                    idx = i;
                    min_priority = p[i].priority;
                    min_remain = p[i].remaining;
                }
            }
        }

        if (idx == -1) {
            ++current_time;
            continue;
        }

        if (p[idx].start == -1) p[idx].start = current_time;

        p[idx].remaining--;
        current_time++;

        if (p[idx].remaining == 0) {
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].response = p[idx].start - p[idx].arrival;
            p[idx].is_completed = true;
            completed++;
        }
    }

    cout << "\nPID\tAT\tBT\tPri\tST\tCT\tRT\tTAT\tWT\n";
    for (auto& proc : p)
        cout << proc.pid << '\t' << proc.arrival << '\t' << proc.burst << '\t' << proc.priority << '\t'
             << proc.start << '\t' << proc.completion << '\t' << proc.response << '\t'
             << proc.turnaround << '\t' << proc.waiting << '\n';

    return 0;
}
