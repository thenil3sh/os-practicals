#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef short unsigned int bool; 
typedef unsigned int time;
typedef struct process Process;


struct process {
    size_t id;
    time arrival;
    time waiting;
    time burst;
    time turnaround;
    time remaining;
    bool executed;
};

inline int by_burst (const void * left, const void * right) {
    return ((Process *) left) -> burst < ((Process *) right) -> burst ? -1 : 1;
}

inline int by_burst_decreasing(const void * left, const void * right) {
    return ((Process *) left) -> burst < ((Process *) right) -> burst ? 1 : -1;
}

inline int by_arrival (const void * left, const void * right) {
    return ((Process *) left) -> arrival < ((Process *) right) -> arrival ? -1 : 1;
}

inline int by_arrival_decreasing (const void * left, const void * right) {
    return ((Process *) left) -> arrival < ((Process *) right) -> arrival ? 1 : -1;
}

inline int by_remaining (const void * left, const void * right) {
    return ((Process *) left) -> remaining < ((Process *) right) -> remaining ? -1 : 1;
}

inline int by_remaining_decreasing (const void * left, const void * right) {
    return ((Process *) left) -> remaining < ((Process *) right) -> remaining ? 1 : -1;
}

#define sort(process_arr, method, size) qsort(process_arr, size, sizeof(*process_arr), method);

void fill(Process process[], size_t len) {
    for (size_t id = 0; id < len; id++) {
        printf("\n\e[1mPROCESS %zu\e[0m\n"
            "Arrival Time : ", id);
            scanf("%u", &process[id].arrival);

            printf("Burst Time : ");
            scanf("%u", &process[id].burst);
            process[id].id = id;
    }
}
    #define insert_into(arr) fill(arr, sizeof(arr)/sizeof(*arr))

#define print_array(arr) print_arr(arr, sizeof(arr)/sizeof(*arr))
void print_arr(Process process[], size_t len) {
    printf("\033[0;31m\e[1mID  ARRIVAL  BURST  WAITING  TURNAROUND\e[m\033[0m\n");
    for (int id = 0; id < len; id++) {
        printf("%2zu  %7d  %5d  %7d  %10d\n",
            process[id].id,
            process[id].arrival,
            process[id].burst,
            process[id].waiting,
            process[id].turnaround);
    }
}

Process* apply_sjf_on(Process process[], size_t size) {
    Process ready_queue[size - 1];
    size_t ready_qsize = 0;
    Process execution_queue[size];
    bool arrival_sorted = false, burst_sorted = false; 
    time t = 0;
    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size; j++) {
            
        }
    }
}

int main () {
    printf("Process count : ");
    unsigned int len; 
    scanf("%u", &len);
    
    Process process[len];
    insert_into(process);
    print_array(process);
}


////////////////////////////////////////////// My Name Convention ////////////
// snake_case // main() bubble_sort() processes process_id arrival_time     // common functions and variables 
// CamelCase  // struct CamelCase , enum Bool, enum Cargo, struct LinkedList// your defined datatypes 
// SCREAMING_SNAKE_CASE // const int PI, static int BRUH, #define A_MACRO() // things that stay throughout the program
// _name // _bruh, _i, _dang_it // prefix unused variable names with _      // rust moment, but it does help keeping track of em