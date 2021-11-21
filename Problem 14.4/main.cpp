#include <iostream>
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
    int N, M, x, y, c;
    cin >> N >> M;


    vector<vector<vector<int>>> minWayMatric(N + 1, vector<vector<int>> (N, vector<int> (N,INT_MAX)));

    for (; M > 0; M--) {
        cin >> x >> y >> c;
        minWayMatric[0][x - 1][y - 1] = c;
        minWayMatric[0][y - 1][x - 1] = c;
    }
    for (int i = 0; i < N; ++i) {
        minWayMatric[0][i][i] = 0;
    }

//    print_doubleVector(minWayMatric[0]);

    for (int k = 1; k <= N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (minWayMatric[k - 1][i][k - 1] == INT_MAX || minWayMatric[k - 1][k - 1][j] == INT_MAX) {
                    minWayMatric[k][i][j] = minWayMatric[k - 1][i][j];
                } else {
                    minWayMatric[k][i][j] = min(minWayMatric[k - 1][i][j],
                                                minWayMatric[k - 1][i][k - 1] + minWayMatric[k - 1][k - 1][j]);
                }
            }
        }
//        print_doubleVector(minWayMatric[k]);
    }
//    print_doubleVector(minWayMatric[N]);


    int K;
    cin >> K;
    for (; K > 0; --K) {
        cin >> x >> y;
        cout << minWayMatric[N][x - 1][y - 1] << endl;
    }
    return 0;
}