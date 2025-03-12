#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned int ID;
typedef unsigned int Time;

class Process {
    private :
        unsigned int id;
        unsigned int priority;
        Time arrival;
        Time execution;
        Time waiting;
        Time turnaround;
        Time response;

    public :
        friend void user_fill(vector<Process>& process);
        friend ostream& operator << (ostream& output, Process process) {
            cout    << setw(2) << process.id 
                    << setw(8) << process.arrival
                    << setw(10)<< process.execution
                    << setw(9) << process.priority;
            return output;
        }
        friend ostream& operator<<(ostream& output, vector<Process> process_vector) {
            if (process_vector.size() == 0) return output; 
            output << "\033[031m\033[01mID ARRIVAL EXECUTION PRIORITY\033[0m" << endl;
            for (auto process : process_vector) {
                cout << process << endl;
            }
            return output;
        };
};


void user_fill(vector<Process>& process) {
    for (size_t id = 0; id < process.size(); id++) {
        cout << "PROCESS ID : " << id << endl;
        process[id].id = id;
        cout << "Arrival : "; cin >> process[id].arrival;
        cout << "Execution : "; cin >> process[id].execution;
    }
}



int main() {
    size_t len;
    cout << "Number of processes : "; cin >> len;
    vector<Process> process(len);
    user_fill(process);
    cout << process;
    return 0;
}