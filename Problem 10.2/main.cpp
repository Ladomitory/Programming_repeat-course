///
///Problem 10.2
///

#include <stdio.h>
#include <stdlib.h>
#include <clocale>

const unsigned int INF = (int) 1e6;

int main() {
    setlocale(LC_ALL, "ru_RU");
    FILE *inp;
    inp = fopen ("input.txt", "r");

    int count = 0, k = 1;
    unsigned char symbol;
    int *a = (int*) calloc (INF, sizeof(int));
    while (fscanf(inp, "%c", &symbol) != EOF) {
        k += 1;
        if (symbol == ' ' || symbol == '\n') {
            a[count]++;
            count = 0;
        } else {
            count++;
        }
    }
    a[count]++;
    fclose (inp);
    for (int i = 1; i < INF; ++i) {
        if (a[i] != 0) {
            printf ("%d - %d\n", i, a[i]);
        }
    }
    free (a);
    return 0;
}