#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int n;
set<int> V;
vector<vector<int>> c;
vector<int> D;

void Dijkstra(int v0) {
    V.erase(v0);
    D[v0] = 0;
    for (int v = 0; v < n; ++v) {
        if (v != v0) {
            D[v] = c[v0][v];
        }
    }
    while (!V.empty()) {
        int w, m = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (V.find(i) != V.end()) {
                if (D[i] <= m) {
                    m = D[i];
                    w = i;
                }
            }
        }
        V.erase(w);
        for (int v = 0; v < n; ++v) {
            if (V.find(v) != V.end() && D[w] != INT_MAX && c[w][v] != INT_MAX) {
                D[v] = min(D[v], D[w] + c[w][v]);
            }
        }
    }
    return;
}

int main() {
    ifstream fin ("input.txt");

    fin >> n;

    //initialization graph matric
    for (int i = 0; i < n; ++i) {
        vector<int> v(n, INT_MAX);
        v[i] = 0;
        c.push_back(v);

        D.push_back(INT_MAX);
        V.insert(i);
    }

    int start, finish;
    fin >> start >> finish;
    start--;
    finish--;

    //filling graph matric
    int x, y, k;
    while (fin >> x >> y >> k) {
        c[x - 1][y - 1] = k;
        c[y - 1][x - 1] = k;
    }

    Dijkstra(start);

    //output ans
    if (D[finish] == INT_MAX) {
        cout << "no" << endl;
    } else {
        cout << D[finish] << endl;
    }
    return 0;
}