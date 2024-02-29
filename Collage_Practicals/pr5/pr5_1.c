#include <stdio.h>
#include <conio.h>

struct process
{
    int p_id;
    int b_time;
    int t_time;
    int w_time;
} p[10];

int main()
{
    int n;
    int sum = 0;
    float avg_T_time = 0;
    float avg_W_time = 0;

    printf("Enter no. of Process = ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Burst time for processing p%d (in ms) : ", i + 1);
        scanf("%d", &p[i].b_time);
        p[i].p_id = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += p[i].b_time;
        p[i].t_time = sum;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].w_time = p[i].t_time - p[i].b_time;
    }

    printf("\n\n\t\tFCFS Scheduling\n");

    printf("\tProcess\tB-Time\tT-Time\tW-Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("\tP(%d)\t%d\t%d\t%d\n", p[i].p_id, p[i].b_time, p[i].t_time, p[i].w_time);
    }

    for (int i = 0; i < n; i++)
    {
        avg_T_time +=p[i].t_time;
        avg_W_time +=p[i].w_time;
    }

    printf("\n\nAverage Turn Around Time = %f",(avg_T_time/n));
    printf("\n\nAverage Waiting Time = %f",(avg_W_time/n));
}