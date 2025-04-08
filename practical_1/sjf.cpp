#include "process.h"
#include <iostream>
#include <vector>

void check_queue (vector <Process>& process_vec, Time current_time, vector <Process> & ready_queue) {
    for (auto &process : process_vec) {
        if (process.state == NotReady && process.arrival < current_time) {
            process.state = Ready;
        }
    }
}