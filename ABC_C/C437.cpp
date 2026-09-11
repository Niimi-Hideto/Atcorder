#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // 乗せる集合をRとすると、引くのは残り全員なので
        //   条件： SP - (Rの力の合計) >= (Rの重さの合計)      ※SP=全員の力の合計
        //   整理： Σ(W_i + P_i) <= SP   (i ∈ R)
        // つまり1匹を「W + P」という1つの値で評価でき、小さい順に選ぶのが最適になる
        vector<long long> cost(n);   // 各トナカイの W + P
        long long sp = 0;            // 全員の力の合計
        for (int i = 0; i < n; i++) {
            long long w, p;
            cin >> w >> p;
            cost.at(i) = w + p;      // W+P は最大2×10^9でintを超えるのでlong long
            sp += p;                 // 合計は最大3×10^14なのでlong long
        }

        // W+P が小さい順に並べる（同じk匹なら、合計が小さいほど条件を満たしやすい）
        sort(cost.begin(), cost.end());

        // 小さい方から1匹ずつ足していき、SPを超えない限り乗せられる
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += cost.at(i);
            if (sum > sp) {
                break;               // これ以上は乗せられない
            }
            ans++;
        }

        cout << ans << endl;
    }
}
