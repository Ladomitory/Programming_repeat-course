///
///Problem 14.3 (Dijkstra)
///By Ladomitory
///

#include <iostream>
#include <fstream>
#include <limits>
#include <set>
#include <algorithm>

using namespace std;

short N, Ss, Sf;
short ServerMap[100][100] = {0};

void basicFilling() {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (i != j) {
                ServerMap[i][j] = INT16_MAX;
            }
        }
    }
}

void scanData() {
    ifstream fin("input.txt");
#define cin fin
    cin >> N;
    cin >> Ss >> Sf;
    short x, y, k;
    while (cin >> x >> y >> k) {
        ServerMap[x - 1][y - 1] = k;
        ServerMap[y - 1][x - 1] = k;
    }
#undef cin
    fin.close();
}

void vectorPrint() {
    cout << "[\n";
    for (short int i = 0; i < N; ++i) {
        cout << "[ ";
        for (short int j = 0; j < N; ++j) {
            cout << ServerMap[i][j] << '\t';
        }
        cout << "]\n";
    }
    cout << "]" << endl;
}

short int Dijkstra(short int v0 = 0, short int vf = 0) {
    set<short int> S;
    S.insert(v0);
    short int D[100] = {0};
//  D[v0] = 0;
    for (short int v = 0; v < N; ++v) {
        if (v != v0) {
            D[v] = ServerMap[v0][v];
        }
    }

    short int min, min_i;
    while (S.size() < N) {
        min = INT16_MAX;
        if (v0 == 1) {
            min_i = 0;
        } else {
            min_i = 1;
        }
        for (short int i = 0; i < N; ++i) {
            if (i != v0 && S.find(i) != S.end() && D[i] < min) {
                min = D[i];
                min_i = i;
            }
        }
        S.insert(min_i);
        for (short int v = 0; v < N; ++v) {
            D[v] = min(D[v], D[min_i] + ServerMap[min_i][v]);
        }
    }
}

int main() {
    basicFilling();
    scanData();
    vectorPrint();
    return 0;
}