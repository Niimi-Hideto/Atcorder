#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    if (a > (b * 2) / 3) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}

// 【改善版】double は誤差リスクがある。両辺を整数倍して整数比較にする
// int a, b; cin >> a >> b;
// if (2 * a > 3 * b) {
//     cout << "Yes" << endl;
// } else {
//     cout << "No" << endl;
// }
