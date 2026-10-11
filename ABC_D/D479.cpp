#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    long long INF = 900000000000LL;
    vector<long long> l(n + 1, INF), r(n + 1, INF);
    for (int i = 2; i <= n; i++) {
        cin >> l.at(i);
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> r.at(i);
    }

    vector<long long> min_l(n + 2, INF), min_r(n + 2, INF);
    for (int i = n; i >= 2; i--) {
        min_l.at(i) = min(l.at(i), min_l.at(i + 1));
    }
    for (int i = 1; i <= n - 1; i++) {
        min_r.at(i) = min(r.at(i), min_r.at(i - 1));
    }

    for (int test = 0; test < q; test++) {
        int s, t;
        cin >> s >> t;

        long long ans = 0;
        if (s > t) {
            ans = min(l.at(s), r.at(s) + min_l.at(s + 1));
        }
        else {
            ans = min(r.at(s), l.at(s) + min_r.at(s - 1));
        }
        cout << ans << endl;
    }
}

/* ===== 改善点 =====
   1. INF を 900000000000LL のように0を数えて書くと桁を見誤りやすい（1WAの原因も INF = 9×10^8 が
      本物のコスト 10^9 より小さかったこと）。1LL << 60（約1.15×10^18）なら十分大きく、INF + INF でも
      約2.3×10^18 で long long（約9.2×10^18）に収まる。const を付けて途中で書き換えないようにする

   const long long INF = 1LL << 60;
*/
