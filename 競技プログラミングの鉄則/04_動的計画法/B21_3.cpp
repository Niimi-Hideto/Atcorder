#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // dp[l][r]：S の l〜r 文字目（1 始まり）から作れる最長の回文の長さ
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    // 1 文字だけの区間は、その 1 文字が回文
    for (int i = 1; i <= n; i++) {
        dp.at(i).at(i) = 1;
    }

    // 回文は両端から内側へ決まるので、dp[l][r] は内側の短い区間から決まる → len を小さいほうから
    for (int len = 1; len <= n - 1; len++) {
        for (int l = 1; l + len <= n; l++) {
            int r = l + len;

            if (s.at(l - 1) == s.at(r - 1)) {
                // 両端が同じ：両端を回文の外側の 2 文字に使い、内側 [l + 1, r - 1] の最長に 2 を足す
                dp.at(l).at(r) = dp.at(l + 1).at(r - 1) + 2;
            }
            else {
                // 両端が違う：どちらかの端は使えないので、左端を捨てるか右端を捨てるかの大きいほう
                dp.at(l).at(r) = max(dp.at(l + 1).at(r), dp.at(l).at(r - 1));
            }
        }
    }

    cout << dp.at(1).at(n) << endl;
}
