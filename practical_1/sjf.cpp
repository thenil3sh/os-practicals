// I used ChatGPT to generate this code, lmao...
// I feel so dumb right now
// In case you're doing it too, just know that, 
// "You're already replacable by AI, if it writes code for you"

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct Process {
  int pid;
  int arrival;
  int burst;
  int start;
  int completion;
  int response;
  int turnaround;
  int waiting;
  bool is_completed = false;
};

bool compareArrival(const Process &a, const Process &b) {
  return a.arrival < b.arrival;
}

int main() {
  int n;
  cout << "Enter number of processes: ";
  cin >> n;

  vector<Process> processes(n);

  // Input arrival and burst times
  for (int i = 0; i < n; ++i) {
    cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
    processes[i].pid = i + 1;
    cin >> processes[i].arrival >> processes[i].burst;
  }

  sort(processes.begin(), processes.end(), compareArrival);

  int completed = 0;
  int current_time = 0;

  while (completed < n) {
    int idx = -1;
    int min_burst = 1e9;

    for (int i = 0; i < n; ++i) {
      if (!processes[i].is_completed && processes[i].arrival <= current_time) {
        if (processes[i].burst < min_burst) {
          min_burst = processes[i].burst;
          idx = i;
        }
      }
    }

    if (idx == -1) {
      current_time++;
    } else {
      processes[idx].start = current_time;
      processes[idx].completion = processes[idx].start + processes[idx].burst;
      processes[idx].turnaround =
          processes[idx].completion - processes[idx].arrival;
      processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
      processes[idx].response = processes[idx].start - processes[idx].arrival;
      processes[idx].is_completed = true;
      current_time = processes[idx].completion;
      completed++;
    }
  }

  // Output
  cout << "PID Arrival Burst Start Completion Response Turnaround Waiting\n";
  for (const auto &p : processes) {
    printf("%3u%8u%6u%6u%11u%9u%11u%7u\n", p.pid, p.arrival, p.burst, p.start,
           p.completion, p.response, p.turnaround, p.waiting);
  }

  return 0;
}
