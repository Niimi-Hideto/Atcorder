#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    /* 自分で書いたもの（A が大きいから DP ではないと考えていたが、表のサイズを決めるのは N で、A は中に入る値。
       横を N にしたので 500000 × 500000 の表になって間に合わない。横は「前の日に勉強したか」の 2 通りで足りる）
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    */

    // 合計は最大 500000 × 10^9 = 5×10^14 で int に入らないので long long
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    // dp[i][0]：i 日目まで決めて、i 日目は勉強しなかったときの実力の上がり幅の最大
    // dp[i][1]：i 日目まで決めて、i 日目は勉強したときの最大
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    for (int i = 1; i <= n; i++) {
        // i 日目に勉強しない → 前の日はどちらでもいいので、大きい方を持ってくる
        dp.at(i).at(0) = max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));
        // i 日目に勉強する → 前の日は勉強していない状態からしか来られない
        dp.at(i).at(1) = dp.at(i - 1).at(0) + a.at(i);
    }

    // 最終日に勉強した／しなかったの大きい方が答え
    cout << max(dp.at(n).at(0), dp.at(n).at(1)) << endl;
}
