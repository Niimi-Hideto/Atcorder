#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    long long x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    long long tmp = 0;
    for (int i = 0; i < k; i++) {
        tmp += a.at(i);
    }

    if (tmp < x) {
        cout << -1 << endl;
        return 0;
    }
    else {
        long long ans = 0;
        int cnt = 0;
        for (int i = k - 1; i >= 0; i--) {
            ans += a.at(i);
            cnt++;
            if (ans >= x) {
                cout << cnt + (n - k) << endl;
                return 0;
            }
        }
    }
}

// 改善案：
// ①24行目の else は不要（直前の if ブロックが return 0; で抜けているため）
//
// ②「可能判定（全部足して届くか）」と「個数のカウント」は同じループにまとめられる。
//   今は2周してるが、大きい方から足していって最後まで届かなければ -1 とすれば1周で済む。
//   cnt も k - i で表せるので変数が1つ減る：
//
//     sort(a.begin(), a.end());
//     long long ans = 0;
//     for (int i = k - 1; i >= 0; i--) {   // Kの中で大きい方から
//         ans += a.at(i);
//         if (ans >= x) {
//             cout << (k - i) + (n - k) << endl;
//             return 0;
//         }
//     }
//     cout << -1 << endl;   // K個全部足しても届かなかった
//
//   ABC447 Cで学んだ「可能判定とカウントを1パスにまとめる」と同じ形