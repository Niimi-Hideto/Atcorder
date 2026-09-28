#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    // 行 i ＝ S を先頭から i 文字目まで見た
    // 列 j ＝ T を先頭から j 文字目まで見た（どちらも 2000 以下なので表は 4×10^6）
    // 中身 ＝ 共通部分列の長さの最大
    // dp.at(i).at(j) = S の先頭 i 文字と T の先頭 j 文字の、最長共通部分列の長さ
    // i = 0 や j = 0（片方が空文字列）は共通部分列も空なので 0。最初に 0 で埋めておけば場合分けが要らない
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // S の i 文字目を使わない / T の j 文字目を使わない
            dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));

            // 2つの最後の文字が同じなら、両方使って共通部分列を1文字伸ばせる
            // （S の i 文字目は s.at(i - 1)。文字列は0始まりなので1ずれる）
            if (s.at(i - 1) == t.at(j - 1)) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - 1) + 1);
            }
        }
    }

    cout << dp.at(n).at(m) << endl;
}
