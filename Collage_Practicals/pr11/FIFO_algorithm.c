#include <stdio.h>

int main()
{
    int i, j, l, rs[50], frame[10], nf, k, avail, count = 0;

    printf("Enter length of ref. string : ");
    scanf("%d", &l);
    printf("Enter reference string :\n");
    for (i = 1; i <= l; i++)
        scanf("%d", &rs[i]);
    printf("Enter number of frames : ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++)
        frame[i] = -1;
    j = 0;

    printf("\nRef. str  Page frames");
    for (i = 1; i <= l; i++)
    {
        printf("\n%4d\t", rs[i]);
        avail = 0;
        for (k = 0; k < nf; k++)
            if (frame[k] == rs[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = rs[i];
            j = (j + 1) % nf;
            count++;
            for (k = 0; k < nf; k++)
                printf("%4d", frame[k]);
        }
    }
    printf("\n\nTotal no. of page faults : %d\n", count);

    return 0;
}

/*
 Output = 
    Enter length of ref. string : 20
    Enter reference string :
    1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
    Enter number of frames : 5 
    
    Ref. str  Page frames
    1       1  -1  -1  -1  -1
    2       1   2  -1  -1  -1
    3       1   2   3  -1  -1
    4       1   2   3   4  -1
    2
    1
    5       1   2   3   4   5
    6       6   2   3   4   5
    2
    1       6   1   3   4   5
    2       6   1   2   4   5
    3       6   1   2   3   5
    7       6   1   2   3   7
    6
    3
    2
    1
    2
    3
    6
    
    Total no. of page faults : 10
*/