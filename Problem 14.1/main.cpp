///
///Problem 14.1 (DFS)
///By Ladomitory
///

#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

const unsigned int INF = (unsigned int) 2e5;

int N;
vector<vector<bool>> Graph(INF, vector<bool> (INF, false));
int Comp[INF] = {0};

void scanData() {
//    ifstream fin ("input.txt");
//    ofstream fout ("output.txt");
//#define cin fin
//#define cout fout

    cin >> N;

    int M, x, y;
    cin >> M;
    for (; M > 0; --M) {
        cin >> x >> y;
        Graph[x - 1][y - 1] = true;
        Graph[y - 1][x - 1] = true;
    }

//#undef cin
//#undef cout
//    fin.close();
//    fout.close();
}

void DFS(int v, int comp) {
    Comp[v] = comp;
    for (int i = 0; i < N; ++i) {
        if (Comp[i] == 0 && Graph[v][i]) {
            DFS(i, comp);
        }
    }
}

int FullDFS() {
    int comp = 1;
    for (int i = 0; i < N; ++i) {
        if (Comp[i] == 0) {
            DFS(i, comp);
            comp++;
        }
    }
    return --comp;
}

void printData() {
    for (int i = 0; i < N; ++i) {
        cout << Comp[i] << ' ';
    }
    cout << endl;
}

int main() {
    scanData();
    int L = FullDFS();
    cout << L << endl;
    printData();
    return 0;
}