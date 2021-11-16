//
//Problem 2.2
//Program by Ladomitory from 09.10.2021
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    cout << stoi(s) << '\n';
    return 0;
}