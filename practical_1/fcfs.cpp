#include <vector>
#include <iostream>
#include "process.h"
using namespace std;


typedef unsigned int ID;
typedef unsigned int Time;

size_t pivot(vector<Process>& vec, size_t left, size_t right, bool (Process::*compare)(Process)) {
    unsigned int pivot = left;
    for (unsigned int i = left; i < right; i++) {
        if ((vec[i].*compare)(vec[pivot])) {
            swap(vec[i], vec[pivot + 1]);
            swap(vec[pivot], vec[pivot + 1]);
            pivot += 1;
        }
    }
    return pivot;
}

ostream& operator << (ostream& output, vector<Process> vec) {
    output << '[';
    for (auto process : vec) {
        output << process.id << ',';
    }
    output << ']';
    return output;
}

void q_sort(vector<Process>& vec, size_t left, size_t right, bool (Process::*compare)(Process)) {
    if (right <= left) {
        return;
    }
    unsigned int piv = pivot(vec, left, right, compare);
    q_sort(vec, left, piv, compare);
    q_sort(vec, piv + 1, right, compare);
}

#define quick_sort(vec, method) q_sort(vec, 0, vec.size(), method)




int main(){
    vector<Process> vec = {
       Process(1, 1, 4),
       Process(2, 1, 3),
       Process(3, 9, 5),
       Process(4, 5, 6),
    };

    cout << "Before sort : " << vec << endl;

    quick_sort(vec, &Process::by_arrival);
    
    Time current_time = vec[0].arrival;
    for (auto process : vec) {
        current_time += current_time + process.execution > process.arrival + process.execution ? process.execution : process.arrival + process.execution;
        process.response = current_time - process.arrival;
        process.completion = current_time;
        process.turnaround = process.completion - process.arrival;
        process.waiting = process.turnaround - process.arrival;
    }

    cout << "After Sort : " << vec << endl;
}
