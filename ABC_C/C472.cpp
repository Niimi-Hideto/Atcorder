#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<pair<long long, bool>> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i).first;
    }

    for (int i = 0; i < n; i++) {
        bool ok = false;
        if (i > m - 1) {
            if (a.at(i - m).second == true) {
                a.at(n).first -= a.at(i - m).first;
            }
        }

        if (a.at(n).first + a.at(i).first <= k) {
            a.at(n).first += a.at(i).first;
            a.at(i).second = true;
            ok = true;
        }

        cout << (ok ? "Yes" : "No") << endl;
    }
}

// 改善点: 配列の余分な1マス(a.at(n))を合計置き場に使うより、専用の変数の方が分かりやすい
// vector<pair<long long, bool>> a(n);
// for (int i = 0; i < n; i++) {
//     cin >> a.at(i).first;
// }
//
// long long window_sum = 0;
// for (int i = 0; i < n; i++) {
//     bool ok = false;
//     if (i > m - 1 && a.at(i - m).second) {
//         window_sum -= a.at(i - m).first;
//     }
//
//     if (window_sum + a.at(i).first <= k) {
//         window_sum += a.at(i).first;
//         a.at(i).second = true;
//         ok = true;
//     }
//
//     cout << (ok ? "Yes" : "No") << endl;
// }
