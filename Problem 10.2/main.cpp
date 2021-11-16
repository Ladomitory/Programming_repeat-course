//
//Problem 10.2
//By Ladomitory
//

// Debug Library //
#include <iostream>
#include <stdlib.h>
// Read&Write Library //
#include <fstream>
#include <stdio.h>
// Container Library //
#include <string>
#include <map>

using namespace std;

const long long INF = (long long) 1.1e9;

int main() {
    // Basic Variables //
    int arr[INF] = {0};
    char symbol;

    FILE *IF;
    IF = fopen ("input.txt", "r");
    // Reading Cycle //
    int ln = 0;
    while (fscanf(IF, "%c", &symbol) != EOF) {
        if (symbol == ' ') {
            arr[ln]++;
        } else {
            ln++;
        }
    }
    fclose(IF);

    ofstream OF("output.txt");
    // Ans Output //
    for (long long i = 0; i < INF; ++i) {
        if (arr[i] > 0) {
            OF << i << " - " << arr[i] << '\n';
        }
    }
    OF.close();

    return 0;
}