///
///Problem 14.2 (BFS)
///By Ladomitory
///

#include <iostream>
#include <queue>
#include <vector>

/*
 * Example of the map in symbols-encoding
 * |---------> y-axes
 * | .....X.
 * | .X..XF.
 * | ..XXXX.
 * | .X.....
 * | .X..X..
 * | S...X..
 * |
 * V x-axes
 *
 * In numbed-encoding:
 *      X     -> -1
 *      S     -> 0
 *      Other -> Length of path from S
 */


using namespace std;

short int M, N, sx, sy, fx, fy; //M - number of string, N - number of column
short int map[100][100] = {0};
vector<vector<bool>> black(100, vector<bool> (100, false));

void scanData() {
    cin >> M >> N;

    char symbol;
    for (short int i = 0; i < M; ++i) {
        for (short int j = 0; j < N; ++j) {
            cin >> symbol;
            if (symbol == 'X') {
                map[i][j] = -1;
            } else if (symbol == 'S') {
                sx = i;
                sy = j;
            } else if (symbol == 'F') {
                fx = i;
                fy = j;
            }
        }
    }
}

void vectorPrint() {
    cout << "[\n";
    for (short int i = 0; i < M; ++i) {
        cout << "[ ";
        for (short int j = 0; j < N; ++j) {
            cout << map[i][j] << '\t';
        }
        cout << "]\n";
    }
    cout << "]" << endl;
}

int BFS() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    black[sx][sy] = true;

    while (!q.empty()) {
//        cout << q.front().first.first << ' ' << q.front().first.second << " - " << q.front().second << endl;
        map[q.front().first.first][q.front().first.second] = q.front().second;
//        vectorPrint();
        if (q.front().first.first > 0
        && map[q.front().first.first - 1][q.front().first.second] > -1
        && !black[q.front().first.first - 1][q.front().first.second]) {
            q.push({{q.front().first.first - 1, q.front().first.second}, q.front().second + 1});
            black[q.front().first.first - 1][q.front().first.second] = true;
//            cout << 1;
        }
        if (q.front().first.first < M - 1
        && map[q.front().first.first + 1][q.front().first.second] > -1
        && !black[q.front().first.first + 1][q.front().first.second]) {
            q.push({{q.front().first.first + 1, q.front().first.second}, q.front().second + 1});
            black[q.front().first.first + 1][q.front().first.second] = true;
//            cout << 2;
        }
        if (q.front().first.second > 0
        && map[q.front().first.first][q.front().first.second - 1] > -1
        && !black[q.front().first.first][q.front().first.second - 1]) {
            q.push({{q.front().first.first, q.front().first.second - 1}, q.front().second + 1});
            black[q.front().first.first][q.front().first.second - 1] = true;
//            cout << 3;
        }
        if (q.front().first.second < N - 1
        && map[q.front().first.first][q.front().first.second + 1] > -1
        && !black[q.front().first.first][q.front().first.second + 1]) {
            q.push({{q.front().first.first, q.front().first.second + 1}, q.front().second + 1});
            black[q.front().first.first][q.front().first.second + 1] = true;
//            cout << 4;
        }
        q.pop();
//        cout << endl;
    }

    return (map[fx][fy] != 0) ? map[fx][fy] : -1;
}

int main() {
    scanData();
    short int ans = BFS();
    cout << ans << endl;
    return 0;
}