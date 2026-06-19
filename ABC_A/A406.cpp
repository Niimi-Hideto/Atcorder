#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flag = true;

    if (a < c) {
        flag = false;
    }
    else if (a == c) {
        if (b < d) {
            flag = false;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}

// 別解：時刻を分換算して1回の比較で済ませる
// int deadline = a * 60 + b;
// int submit = c * 60 + d;
// if (submit < deadline) {
//     cout << "Yes" << endl;
// }
// else {
//     cout << "No" << endl;
// }
