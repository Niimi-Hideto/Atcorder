#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x;
    cin >> t >> x;

    int tmp = 0;
    cin >> tmp;

    cout << 0 << " " << tmp << endl;

    for (int i = 1; i < t + 1; i++) {
        int a = 0;
        cin >> a;

        if ((a - tmp) >= x || (a - tmp) <= -x) {
            tmp = a;
            cout << i << " " << tmp << endl;
        }
    }
}

// abs版
// if (abs(a - tmp) >= x) {