//
//Problem 2.3
//By Ladomitory from 09.10.2021
//

#include <iostream>
#include <algorithm>
23
using namespace std;

void Test_SimpleNumber(int a) {
    int d = 2;
    for (; d * d <= a && a % d != 0; ++d) {}
    if (d * d > a) {
        cout << a << ' ';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; {
        cin >> n;
    }
    for (int p = 2; p <= n; ++p) {
        Test_SimpleNumber(p);
    }
    return 0;
}