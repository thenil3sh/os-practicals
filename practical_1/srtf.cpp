#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid, arrival, burst, remaining, start = -1, completion;
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
        cout << "Arrival and Burst time for P" << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1, min_remain = 1e9;

        for (int i = 0; i < n; ++i) {
            if (!p[i].is_completed && p[i].arrival <= current_time && p[i].remaining < min_remain && p[i].remaining > 0) {
                min_remain = p[i].remaining;
                idx = i;
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

    cout << "\nPID\tAT\tBT\tST\tCT\tRT\tTAT\tWT\n";
    for (auto& proc : p)
        cout << proc.pid << '\t' << proc.arrival << '\t' << proc.burst << '\t' << proc.start
             << '\t' << proc.completion << '\t' << proc.response << '\t' << proc.turnaround
             << '\t' << proc.waiting << '\n';

    return 0;
}
