#include <vector>
#include <iostream>
using namespace std;

typedef unsigned int Time;
typedef unsigned int size;

enum State {
    Completed, 
    Ready,
    NotReady,
};

class Process {
    
    public : 
        unsigned int id;
        unsigned int prority;
        Time arrival;
        Time execution;
        Time waiting;
        Time turnaround;
        Time response;
        Time completion;
        State state;
        
        
        bool by_arrival(Process b) {
            return arrival < b.arrival;
        } 
        
        bool by_id(Process b) {
            return id < b.id;
        }

        bool by_arrival_then_burst(Process b) {
            if (arrival < b.arrival) {
                return true;
            } else if (arrival == b.arrival) {
                return execution < b.execution;
            } else {
                return false;
            }
        }

        friend void quick_sort(vector<Process>, size_t, size_t, bool (Process::*)(Process, Process));
        friend size_t pivot   (vector<Process>, size_t, size_t, bool (Process::*)(Process, Process));

        Process (unsigned int id, Time arrival, Time execution) :
        id(id), arrival(arrival), execution(execution) {};

        friend ostream& operator << (ostream& output, vector<Process>);
};




