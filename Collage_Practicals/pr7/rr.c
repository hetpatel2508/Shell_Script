#include <stdio.h>

int main()
{
    int i, x = -1, k[10], m = 0, n, t, s = 0;
    int a[50], temp, b[50], p[10], bur[10], bur1[10];
    int wat[10], tur[10], ttur = 0, twat = 0, j = 0;
    float awat, atur;

    printf("Enter no. of process : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Burst time for process P%d : ", (i + 1));
        scanf("%d", &bur[i]);
        bur1[i] = bur[i];
    }
    printf("Enter the time slice (in ms) : ");
    scanf("%d", &t);

    for (i = 0; i < n; i++)
    {
        b[i] = bur[i] / t;
        if ((bur[i] % t) != 0)
            b[i] += 1;
        m += b[i];
    }

    printf("\n\t\tRound Robin Scheduling\n");

    printf("\nGANTT Chart\n");
    for (i = 0; i < m; i++)
        printf("--------");
    printf("\n");

    a[0] = 0;
    while (j < m)
    {
        if (x == n - 1)
            x = 0;
        else
            x++;
        if (bur[x] >= t)
        {
            bur[x] -= t;
            a[j + 1] = a[j] + t;

            if (b[x] == 1)
            {
                p[s] = x;
                k[s] = a[j + 1];
                s++;
            }
            j++;
            b[x] -= 1;
            printf("  P%d    |", x + 1);
        }
        else if (bur[x] != 0)
        {
            a[j + 1] = a[j] + bur[x];
            bur[x] = 0;
            if (b[x] == 1)
            {
                p[s] = x;
                k[s] = a[j + 1];
                s++;
            }
            j++;
            b[x] -= 1;
            printf("  P%d  |", x + 1);
        }
    }

    printf("\n");
    for (i = 0; i < m; i++)
        printf("--------");
    printf("\n");

    for (j = 0; j <= m; j++)
        printf("%d\t", a[j]);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        wat[i] = k[i] - bur1[i];
        tur[i] = k[i];
    }
    for (i = 0; i < n; i++)
    {
        ttur += tur[i];
        twat += wat[i];
    }

    printf("\n\n");
    for (i = 0; i < 30; i++)
        printf("-");
    printf("\nProcess\tBurst\tTrnd\tWait\n");
    for (i = 0; i < 30; i++)
        printf("-");
    for (i = 0; i < n; i++)
        printf("\nP%-4d\t%4d\t%4d\t%4d", p[i] + 1, bur1[i], tur[i], wat[i]);
    printf("\n");
    for (i = 0; i < 30; i++)
        printf("-");

    awat = (float)twat / n;
    atur = (float)ttur / n;
    printf("\n\nAverage waiting time     : %.2f ms", awat);
    printf("\nAverage turn around time : %.2f ms\n", atur);

    return 0;
}


/*
 Output = 

    Enter no. of process : 5
    Burst time for process P1 : 10
    Burst time for process P2 : 29
    Burst time for process P3 : 3
    Burst time for process P4 : 7
    Burst time for process P5 : 12
    Enter the time slice (in ms) : 10
    
                    Round Robin Scheduling
    
    GANTT Chart
    ----------------------------------------------------------------
    P1    |  P2    |  P3  |  P4  |  P5    |  P2    |  P5  |  P2  |
    ----------------------------------------------------------------
    0       10      20      23      30      40      50      52      61
    
    ------------------------------
    Process Burst   Trnd    Wait
    ------------------------------
    P1        10      10       0
    P2        29      61      32
    P3         3      23      20
    P4         7      30      23
    P5        12      52      40
    ------------------------------
    
    Average waiting time     : 23.00 ms
    Average turn around time : 35.20 ms
*/