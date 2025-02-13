#include <stdio.h>

////////////// macro definition for average calculation //////////////////////
// works only with structs + the array should be declared in same scope this macro is called  
#define print_average(array, keyword) avg(array, keyword, sizeof(array)/sizeof(array[0]));
#define avg(array, keyword, size) if (1) {float sum = 0, count = 0;\
    for (unsigned int i = 0; i < size; i++) count++, sum += array[i].keyword; \
    printf("%g\n", sum/count);}

/////////// Process struct definition ////////////
typedef struct process Process;
struct process {
    unsigned int id;
    unsigned int arrival_time;
    unsigned int burst_time;
    unsigned int waiting_time;
    unsigned int turnaround_time;
};

int main() {
    unsigned int process_count;
    printf("Number of processes ? : ");
    scanf("%d", &process_count);

    Process process[process_count];

    ///////////////////////// Insertion Loop ///////////////////////
    unsigned int time = 0;
    for (int id = 0; id < process_count; id++) {                
        printf("\n\e[1mPROCESS ID : %d\e[m\n"                 
                "Arrival time : %d\n"                           
                "Burst time : ",                                
            id, id);                                            
        scanf("%d", &process[id].burst_time);
        time += process[id].burst_time;
        process[id].id = id;
        process[id].arrival_time = id;
        process[id].turnaround_time = time - process[id].arrival_time;
        process[id].waiting_time = process[id].turnaround_time - process[id].burst_time;
    }

    ///////////////////////////// Printing Loop /////////////////////////////////
    printf("\033[0;31m\e[1mID  ARRIVAL  BURST  WAITING  TURNAROUND\e[m\033[0m\n");
    for (int id = 0; id < process_count; id++) {
        printf("%2d  %7d  %5d  %7d  %10d\n",
            process[id].id,
            process[id].arrival_time,
            process[id].burst_time,
            process[id].waiting_time,
            process[id].turnaround_time);
    }
    printf("\e[1mAverage Waiting : \e[m"); print_average(process, waiting_time);
    printf("\e[1mAverage Turnaround : \e[m"); print_average(process, turnaround_time);
}