#include <stdio.h>
#include <conio.h>

struct process {
    int p_id;
    int b_time;
    int t_time;
    int w_time;
};

int main() {
    int n;
    int sum = 0;
    float avg_T_time = 0;
    float avg_W_time = 0;

    printf("Enter no. of Process: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Burst time for processing p%d (in ms): ", i + 1);
        scanf("%d", &p[i].b_time);
        p[i].p_id = i + 1;
    }

    for (int i = 0; i < n; i++) {
        sum += p[i].b_time;
        p[i].t_time = sum;
    }

    for (int i = 0; i < n; i++) {
        p[i].w_time = p[i].t_time - p[i].b_time;
    }

    printf("\n\n\t\tFCFS Scheduling\n");
    printf("\tProcess\tB-Time\tT-Time\tW-Time\n");
    for (int i = 0; i < n; i++) {
        printf("\tP(%d)\t%d\t%d\t%d\n", p[i].p_id, p[i].b_time, p[i].t_time, p[i].w_time);
    }

    // Printing Gantt chart
    printf("\nGantt Chart:\n");
    printf("-------------------------------------\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("   P%d  |", p[i].p_id);
    }
    printf("\n-----------------------------------\n");
    printf("0\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", p[i].t_time);
    }
    printf("\n");

    // Calculating average turnaround time and average waiting time
    for (int i = 0; i < n; i++) {
        avg_T_time += p[i].t_time;
        avg_W_time += p[i].w_time;
    }

    printf("\nAverage Turn Around Time: %.2f\n", (avg_T_time / n));
    printf("\nAverage Waiting Time: %.2f\n", (avg_W_time / n));

    return 0;
}


/*
 Output =

    Enter no. of Process: 4
    Burst time for processing p1 (in ms): 10
    Burst time for processing p2 (in ms): 4
    Burst time for processing p3 (in ms): 11
    Burst time for processing p4 (in ms): 6
    
    
                    FCFS Scheduling
            Process B-Time  T-Time  W-Time
            P(1)    10      10      0
            P(2)    4       14      10
            P(3)    11      25      14
            P(4)    6       31      25
    
    Gantt Chart:
    -------------------------------------
    |   P1  |   P2  |   P3  |   P4  |
    -----------------------------------
    0       10      14      25      31
    
    Average Turn Around Time: 20.00
    
    Average Waiting Time: 12.25
*/