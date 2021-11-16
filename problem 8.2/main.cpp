//
//Problem 8.2
//By Ladomitory from 09/10/2021
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int revn = 0;
    for (int i = 31,  pow2 = 1; i >= 0; --i, pow2 *= 2) {
        cout << ((n >> i) & 1); //так как 1 в двоичной 000...0001, то после & 1 останется значение в последней клетке.
        revn += ((n >> i) & 1) * pow2;
    }
    cout << '\n' << revn << '\n';
    for (int i = 31; i >= 0; --i) {
        cout << ((revn >> i) & 1);
    }
    cout << '\n';
    return 0;
}
