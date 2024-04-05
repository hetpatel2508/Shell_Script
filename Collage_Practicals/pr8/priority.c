#include <stdio.h>

struct process
{
    int pid;
    int btime;
    int pri;
    int wtime;
    int ttime;
} p[10], temp;

int main()
{
    int i, j, k, n, ttur, twat;
    float awat, atur;

    printf("Enter no. of process : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Burst time for process P%d (in ms) : ", (i + 1));
        scanf("%d", &p[i].btime);
        printf("Priority for process P%d : ", (i + 1));
        scanf("%d", &p[i].pri);
        p[i].pid = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((p[i].pri > p[j].pri) ||
                (p[i].pri == p[j].pri && p[i].pid > p[j].pid))
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    p[0].wtime = 0;
    for (i = 0; i < n; i++)
    {
        p[i + 1].wtime = p[i].wtime + p[i].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
    }

    ttur = twat = 0;
    for (i = 0; i < n; i++)
    {
        ttur += p[i].ttime;
        twat += p[i].wtime;
    }
    awat = (float)twat / n;
    atur = (float)ttur / n;

    printf("\n\t Priority Scheduling\n\n");
    for (i = 0; i < 38; i++)
        printf("-");
    printf("\nProcess B-Time Priority T-Time  W-Time\n");
    for (i = 0; i < 38; i++)
        printf("-");
    for (i = 0; i < n; i++)
        printf("\n  P%-4d\t%4d\t%3d\t%4d\t%4d", p[i].pid, p[i].btime, p[i].pri, p[i].ttime, p[i].wtime);
    printf("\n");
    for (i = 0; i < 38; i++)
        printf("-");

    printf("\n\nGANTT Chart\n");
    printf("-");
    for (i = 0; i < (p[n - 1].ttime + 2 * n); i++)
        printf("-");
    printf("\n|");
    for (i = 0; i < n; i++)
    {
        k = p[i].btime / 2;
        for (j = 0; j < k; j++)
            printf(" ");
        printf("P%d", p[i].pid);
        for (j = k + 1; j < p[i].btime; j++)
            printf(" ");
        printf("|");
    }
    printf("\n-");
    for (i = 0; i < (p[n - 1].ttime + 2 * n); i++)
        printf("-");
    printf("\n0");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p[i].btime; j++)
            printf(" ");
        printf("%2d", p[i].ttime);
    }

    printf("\n\nAverage waiting time     : %5.2fms", awat);
    printf("\nAverage turn around time : %5.2fms\n", atur);

    return 0;
}

/*
 Output =

    Enter no. of process : 5
    Burst time for process P1 (in ms) : 10
    Priority for process P1 : 3
    Burst time for process P2 (in ms) : 7
    Priority for process P2 : 1
    Burst time for process P3 (in ms) : 6
    Priority for process P3 : 3
    Burst time for process P4 (in ms) : 13
    Priority for process P4 : 4
    Burst time for process P5 (in ms) : 5   
    Priority for process P5 : 2
    
            Priority Scheduling
    
    --------------------------------------
    Process B-Time Priority T-Time  W-Time
    --------------------------------------
    P2       7      1        7       0
    P5       5      2       12       7
    P1      10      3       22      12
    P3       6      3       28      22
    P4      13      4       41      28
    --------------------------------------
    
    GANTT Chart
    ----------------------------------------------------
    |   P2   |  P5  |     P1    |   P3  |      P4      |
    ----------------------------------------------------
    0        7     12          22      28             41
    
    Average waiting time     : 13.80ms
    Average turn around time : 22.00ms
*/