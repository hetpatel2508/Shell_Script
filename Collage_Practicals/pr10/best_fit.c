#include <stdio.h>

struct process
{
    int size;
    int flag;
    int holeid;
} p[10];
struct hole
{
    int hid;
    int size;
    int actual;
} h[10];

int main()
{
    int i, np, nh, j;
    void bsort(struct hole[], int);

    printf("Enter the number of Holes : ");
    scanf("%d", &nh);
    for (i = 0; i < nh; i++)
    {
        printf("Enter size for hole H%d : ", i);
        scanf("%d", &h[i].size);
        h[i].actual = h[i].size;
        h[i].hid = i;
    }

    printf("\nEnter number of process : ");
    scanf("%d", &np);
    for (i = 0; i < np; i++)
    {
        printf("enter the size of process P%d : ", i);
        scanf("%d", &p[i].size);
        p[i].flag = 0;
    }

    for (i = 0; i < np; i++)
    {
        bsort(h, nh);

        for (j = 0; j < nh; j++)
        {
            if (p[i].flag != 1)
            {
                if (p[i].size <= h[j].size)
                {
                    p[i].flag = 1;
                    p[i].holeid = h[j].hid;
                    h[j].size -= p[i].size;
                }
            }
        }
    }

    printf("\n\tBest fit\n");
    printf("\nProcess\tPSize\tHole");
    for (i = 0; i < np; i++)
    {
        if (p[i].flag != 1)
            printf("\nP%d\t%d\tNot allocated", i, p[i].size);
        else
            printf("\nP%d\t%d\tH%d", i, p[i].size, p[i].holeid);
    }

    printf("\n\nHole\tActual\tAvailable");
    for (i = 0; i < nh; i++)
        printf("\nH%d\t%d\t%d", h[i].hid, h[i].actual, h[i].size);
    printf("\n");

    return 0;
}

void bsort(struct hole bh[], int n)
{
    struct hole temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bh[i].size > bh[j].size)
            {
                temp = bh[i];
                bh[i] = bh[j];
                bh[j] = temp;
            }
        }
    }
}

/*
 Output =

    Enter the number of Holes : 5
    Enter size for hole H0 : 100
    Enter size for hole H1 : 500
    Enter size for hole H2 : 200
    Enter size for hole H3 : 300
    Enter size for hole H4 : 600
    
    Enter number of process : 4
    enter the size of process P0 : 212
    enter the size of process P1 : 417
    enter the size of process P2 : 112
    enter the size of process P3 : 426
    
            Best fit
    
    Process PSize   Hole
    P0      212     H3
    P1      417     H1
    P2      112     H2
    P3      426     H4
    
    Hole    Actual  Available
    H1      500     83
    H3      300     88
    H2      200     88
    H0      100     100
    H4      600     174
*/