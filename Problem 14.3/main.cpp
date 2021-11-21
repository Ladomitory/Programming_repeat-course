#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> matric;

void Dijkstra(int e, vector<int> *minWay)
{
    vector<pair<int, int>> queue; //очередь
    vector<int> map(matric.size(), 0); //?
    queue.push_back({e, -1});
    int v;
    while (!queue.empty())
    {
        e = queue[0].first;
        v = queue[0].second;
        queue.erase(queue.begin()); //взятие и удаление первого в очереди
        if (v == -1)
            (*minWay)[e] = 0; //если начальная вершина, то 0
        else
            (*minWay)[e] = min((*minWay)[v] + matric[v][e], (*minWay)[e]);
        for (int i = 0; i < matric.size(); ++i)
            if (i != e && matric[e][i] > 0 && (*minWay)[i] > (*minWay)[e] + matric[e][i])
            {
                queue.push_back({i, e});
            }

    }
    return;
}

int main()
{
    ifstream fin("input.txt");

    int n, s, f;
    fin >> n >> s >> f;
    for (int i = 0; i < n; ++i) {
        vector<int> v(n, 0);
        matric.push_back(v);
    }
    int x, y, a;
    while (fin >> x >> y >> a) {
        matric[x - 1][y - 1] = a;
        matric[y - 1][x - 1] = a;
    }

    vector<int> minWay(n, INT_MAX);
    Dijkstra(s - 1, &minWay);
    if (minWay[f - 1] == INT_MAX) {
        cout << "NO" << endl;
    } else {
        cout << minWay[f - 1] << endl;
    }
    return 0;
}