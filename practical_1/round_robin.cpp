#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int pid, arrival, burst, remaining, start = -1, completion;
    int response, turnaround, waiting;
};

int main() {
    int n, tq;
    cout << "Enter number of processes and time quantum: ";
    cin >> n >> tq;

    vector<Process> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Arrival and Burst time for P" << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    queue<int> q;
    vector<bool> in_queue(n, false);
    int current_time = 0, completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; ++i)
            if (p[i].arrival <= current_time && !in_queue[i] && p[i].remaining > 0) {
                q.push(i);
                in_queue[i] = true;
            }

        if (q.empty()) {
            current_time++;
            continue;
        }

        int idx = q.front(); q.pop();

        if (p[idx].start == -1)
            p[idx].start = current_time;

        int exec_time = min(tq, p[idx].remaining);
        current_time += exec_time;
        p[idx].remaining -= exec_time;

        for (int i = 0; i < n; ++i)
            if (p[i].arrival <= current_time && !in_queue[i] && p[i].remaining > 0) {
                q.push(i);
                in_queue[i] = true;
            }

        if (p[idx].remaining > 0)
            q.push(idx);
        else {
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].response = p[idx].start - p[idx].arrival;
            completed++;
        }
    }

    cout << "\nPID\tAT\tBT\tST\tCT\tRT\tTAT\tWT\n";
    for (auto& proc : p)
        cout << proc.pid << '\t' << proc.arrival << '\t' << proc.burst << '\t' << proc.start << '\t'
             << proc.completion << '\t' << proc.response << '\t' << proc.turnaround << '\t'
             << proc.waiting << '\n';

    return 0;
}
