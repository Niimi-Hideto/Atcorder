#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    // たどり着けない状態の印（最大を求めるので、とても小さい値）
    const int INF = 1000000000;

    // dp[i][j]：1〜i ページ目を、ちょうど j 個の章に分けたときの良さの最大
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
    dp.at(0).at(0) = 0;  // まだ何も分けていない

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // j 個目の章が l + 1 〜 i ページ目だとして、l を全部試す
            for (int l = 0; l < i; l++) {
                // l ページ目までを j − 1 個に分けられないなら飛ばす
                if (dp.at(l).at(j - 1) == -INF) continue;

                // l + 1 〜 i ページ目に両端が入る繋がりの数
                int cnt = 0;
                for (int x = 1; x <= m; x++) {
                    if (l + 1 <= a.at(x) && b.at(x) <= i) cnt++;
                }

                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(l).at(j - 1) + cnt);
            }
        }
    }

    // N ページ全部を K 個の章に分けたときの最大
    cout << dp.at(n).at(k) << endl;
}
