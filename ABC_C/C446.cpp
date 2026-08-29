#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n), b(n), sum_a(n), sum_b(n);
        for (int i = 0; i < n; i++) {
            cin >> a.at(i);
            if (i == 0) {
                sum_a.at(i) = a.at(i);
            }
            else {
                sum_a.at(i) = sum_a.at(i - 1);
                sum_a.at(i) += a.at(i);
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> b.at(i);
            if (i == 0) {
                sum_b.at(i) = b.at(i);
            }
            else {
                sum_b.at(i) = sum_b.at(i - 1);
                sum_b.at(i) += b.at(i);
            }
        }

        int ans = 0;
        int delate = 0;
        for (int i = 0; i < n; i++) {
            ans += a.at(i);
            ans -= b.at(i);

            if (i - d >= 0 && sum_a.at(i - d) > sum_b.at(i) + delate) {
                ans -= (sum_a.at(i - d) - (sum_b.at(i) + delate));
                delate += (sum_a.at(i - d) - (sum_b.at(i) + delate));
            }
        }
        cout << ans << endl;
    }
}

// 改善案：
// ①累積和は番兵行(サイズn+1、先頭を0)を使うとif(i==0)の場合分けが不要になる
// ②41行目のdelate更新は打ち消し合って結局この代入と同じ
//
// vector<int> sum_a(n + 1, 0), sum_b(n + 1, 0);
// for (int i = 0; i < n; i++) {
//     cin >> a.at(i);
//     sum_a.at(i + 1) = sum_a.at(i) + a.at(i);
// }
// for (int i = 0; i < n; i++) {
//     cin >> b.at(i);
//     sum_b.at(i + 1) = sum_b.at(i) + b.at(i);
// }
// ...
// if (i - d >= 0 && sum_a.at(i - d + 1) > sum_b.at(i + 1) + delate) {
//     ans -= (sum_a.at(i - d + 1) - (sum_b.at(i + 1) + delate));
//     delate = sum_a.at(i - d + 1) - sum_b.at(i + 1); // +=ではなく直接代入でOK
// }
