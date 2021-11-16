//
//By Ladomitory from 29.10
//

#include <iostream>

using namespace std;

void QuickSort(int * mas, int size) {
    int l = 0, r = size - 1;
    int m = mas[size / 2];

    do {
        while (mas[l] < m) {
            ++l;
        }
        while (mas[r] > m) {
            --r;
        }

        if (l <= r) {
            int c = mas[l];
            mas[l] = mas[r];
            mas[r] = c;

            l++;
            --r;
        }
    } while (l <= r);

    if (r > 0) {
        QuickSort(mas, r + 1);
    }
    if (l < size - 1) {
        QuickSort(&mas[l], size - l);
    }
}

int main() {
    int n;
    cin >> n;
    int * mas = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
    }
    QuickSort(mas, n);
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << ' ';
    }
    cout << endl;
    return 0;
}