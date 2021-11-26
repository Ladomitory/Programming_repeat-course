#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ifstream fin("input.txt");
#define cin fin

    int N, M;
    cin >> N >> M;

    vector<vector<unsigned int>> minWayMatric(N, vector<unsigned int> (N, UINT_MAX));

    unsigned int x, y, c;
    for (; M > 0; M--) {
        cin >> x >> y >> c;
        minWayMatric[x - 1][y - 1] = min(minWayMatric[x - 1][y - 1], c);
        minWayMatric[y - 1][x - 1] = minWayMatric[x - 1][y - 1];
    }
    for (int i = 0; i < N; ++i) {
        minWayMatric[i][i] = 0;
    }

    for (int k = 0; k < N; ++k) {
        vector<vector<unsigned int>> minWayMatricCopy(minWayMatric);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (minWayMatricCopy[i][k] == UINT_MAX || minWayMatricCopy[k][j] == UINT_MAX) {
                    minWayMatric[i][j] = minWayMatricCopy[i][j];
                } else {
                    minWayMatric[i][j] = min(minWayMatricCopy[i][j], minWayMatricCopy[i][k] + minWayMatricCopy[k][j]);
                }
            }
        }
    }

    int K;
    cin >> K;
    for (; K > 0; --K) {
        cin >> x >> y;
        cout << minWayMatric[x - 1][y - 1] << endl;
    }
#undef cin
    return 0;
}