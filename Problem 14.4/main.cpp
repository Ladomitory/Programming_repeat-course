#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void print_doubleVector(vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << '\n';
    }
    cout << endl;
}

int main()
{
    ifstream fin("input.txt");
#define cin fin


    int N, M, x, y, c;
    cin >> N >> M;


    vector<vector<unsigned int>> minWayMatric(N, vector<unsigned int> (N, UINT_MAX));

    for (; M > 0; M--) {
        cin >> x >> y >> c;
        minWayMatric[x - 1][y - 1] = c;
        minWayMatric[y - 1][x - 1] = c;
    }
    for (int i = 0; i < N; ++i) {
        minWayMatric[i][i] = 0;
    }
//    cout << ")" << endl;
//    print_doubleVector(minWayMatric);

    for (int k = 1; k <= N; ++k) {
        vector<vector<unsigned int>> minWayMatricCopy(minWayMatric);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
//                cout << k - 1 << ") " << i << ' ' << j << endl;
                if (minWayMatricCopy[i][k - 1] == UINT_MAX || minWayMatricCopy[k - 1][j] == UINT_MAX) {
                    minWayMatric[i][j] = minWayMatricCopy[i][j];
                } else {
                    minWayMatric[i][j] = min(minWayMatricCopy[i][j],
                                             minWayMatricCopy[i][k - 1] + minWayMatricCopy[k - 1][j]);
                }
//                cout << minWayMatricCopy[i][j] << " ? "
//                    << minWayMatricCopy[i][k - 1] << " + " << minWayMatricCopy[k - 1][j] << endl;
//                print_doubleVector(minWayMatric);
            }
        }
    }
//    cout << N << ')' << endl;
//    print_doubleVector(minWayMatric);
//#undef cin

    int K;
    cin >> K;
    for (; K > 0; --K) {
        cin >> x >> y;
        cout << minWayMatric[x - 1][y - 1] << endl;
    }
    return 0;
}