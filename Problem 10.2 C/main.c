///
///Problem 10.2
///

#include <stdio.h>
#include <stdlib.h>

const unsigned int INF = (int) 1e6;

int main() {
    FILE *inp;
    inp = fopen ("input.txt", "r");

    int count = 0, k = 1;
    unsigned char symbol;
    int *a = (int*) calloc (INF, sizeof(int));
    while (fscanf(inp, "%c", &symbol) != EOF) {
        k += 1;
        if (symbol == ' ') {
            a[count]++;
            count = 0;
        } else {
            count++;
        }
    }
    a[count]++;
    fclose (inp);

//    FILE *outp;
//    outp = fopen("output.txt", "w");
    for (int i = 0; i < INF; ++i) {
        if (a[i] != 0) {
            printf ("%d - %d\n", i, a[i]);
        }
    }
//    fclose (outp);
    free (a);
    return 0;
}