#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a <= c) {
        if (b <= d) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}

// 別解：条件を1行にまとめる
// if (c >= a && d < b) cout << "Yes" << endl;
// else cout << "No" << endl;
