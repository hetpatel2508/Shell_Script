#include <stdio.h>

// Define a structure to represent a process
struct Process {
    int pid;            // Process ID
    int burst_time;     // Burst time
    int waiting_time;   // Waiting time
    int turnaround_time;// Turnaround time
};

int main() {
    int n; // Number of processes
    float average_waiting_time, average_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare an array to store information about the processes
    struct Process p[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process P%d (in ms): ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
    }

    // Sort processes based on burst time (SJF scheduling)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burst_time > p[j + 1].burst_time || 
                (p[j].burst_time == p[j + 1].burst_time && p[j].pid > p[j + 1].pid)) {
                // Swap processes
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    p[0].waiting_time = 0;
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        if (i < n - 1) {
            p[i + 1].waiting_time = p[i].turnaround_time;
        }
    }

    // Calculate average waiting time and average turnaround time
    average_waiting_time = 0;
    average_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        average_waiting_time += p[i].waiting_time;
        average_turnaround_time += p[i].turnaround_time;
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;

    // Display Gantt chart
    printf("\nGantt Chart:\n");
    printf("-----------------------------------------------\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("   P%d  |", p[i].pid);
    }
    printf("\n-----------------------------------------------\n");
    printf("0\t");
    int total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += p[i].burst_time;
        printf("%d\t", total_time);
    }
    printf("\n");

    // Display process information
    printf("\nProcess   Burst Time   Turnaround Time   Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%-9d %-12d %-16d %d\n", p[i].pid, p[i].burst_time, p[i].turnaround_time, p[i].waiting_time);
    }
    printf("\nAverage Waiting Time: %.2f ms\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f ms\n", average_turnaround_time);

    return 0;
}

/*
 Output :

    Enter the number of processes: 5
    Enter burst time for process P1 (in ms): 10
    Enter burst time for process P2 (in ms): 6
    Enter burst time for process P3 (in ms): 5
    Enter burst time for process P4 (in ms): 6
    Enter burst time for process P5 (in ms): 9
    
    Gantt Chart:
    -----------------------------------------------
    |   P3  |   P2  |   P4  |   P5  |   P1  |
    -----------------------------------------------
    0       5       11      17      26      36
    
    Process   Burst Time   Turnaround Time   Waiting Time
    P3         5            5                0
    P2         6            11               5
    P4         6            17               11
    P5         9            26               17
    P1         10           36               26
    
    Average Waiting Time: 11.80 ms
    Average Turnaround Time: 19.00 ms
*/