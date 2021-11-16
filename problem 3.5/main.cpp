//
//Problem 3.5
//By Ladomitory from 09.10.2021
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, S;
    cin >> n >> S;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set <int> IntervalStartIndex;
    int ans = 0;
    for (int si = 0; si < n; ++si) {
        int s = 0, isi = si; /*s - summ, isi - intervalstartindex*/
        for (int iei = si; iei < n; ++iei) /* iei - intervalendindex*/ {
            s += a[iei];
            if (s > S) {
                do {
                    s -= a[isi++];
                } while (s > S);
            }
            if (s == S) {
                if (IntervalStartIndex.find(isi) == IntervalStartIndex.end()) {
                    IntervalStartIndex.insert(isi);
                    ans += 1;
                }
                do {
                    s -= a[isi++];
                } while (s > S);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}