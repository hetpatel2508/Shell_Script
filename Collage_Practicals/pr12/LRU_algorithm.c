#include <stdio.h>

int arrmin(int[], int);

int main() {
    int i, len, nf, count = 0;
    int rs[50], frame[10], access[10] = {0};

    printf("Length of Reference string: ");
    scanf("%d", &len);

    printf("Enter reference string:\n");
    for (i = 0; i < len; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++)
        frame[i] = -1;

    printf("\nRef. str   Page\t frames");
    for (i = 0; i < len; i++) {
        printf("\n%4d\t", rs[i]);
        int avail = 0;
        for (int k = 0; k < nf; k++) {
            if (frame[k] == rs[i]) {
                avail = 1;
                access[k] = i + 1;
                break;
            }
        }
        if (avail == 0) {
            int dm = 0, j;
            for (int k = 0; k < nf; k++) {
                if (frame[k] == -1) {
                    dm = 1;
                    j = k;
                    break;
                }
            }
            if (dm == 1) {
                frame[j] = rs[i];
                access[j] = i + 1;
                count++;
            } else {
                j = arrmin(access, nf);
                frame[j] = rs[i];
                access[j] = i + 1;
                count++;
            }
            for (int k = 0; k < nf; k++)
                printf("%4d", frame[k]);
        }
    }
    printf("\n\nTotal number of page faults: %d\n", count);

    return 0;
}

int arrmin(int a[], int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[min_index])
            min_index = i;
    }
    return min_index;
}

/*
 Output = 

    Length of Reference string: 20
    Enter reference string:
    1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6
    Enter number of frames: 5
    
    Ref. str   Page frames
       1       1  -1  -1  -1  -1
       2       1   2  -1  -1  -1
       3       1   2   3  -1  -1
       4       1   2   3   4  -1
       2
       1
       5       1   2   3   4   5
       6       1   2   6   4   5
       2
       1
       2
       3       1   2   6   3   5
       7       1   2   6   3   7
       6
       3
       2
       1
       2
       3
       6
    
    Total number of page faults: 8
*/