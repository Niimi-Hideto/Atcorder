#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // dp[i][j]：コマが i 段目の左から j 番目にあるとき、そこから両者が最善を尽くしたときのスコア
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    // 最下段：もう動かせないので、書かれた数がそのままスコア
    for (int j = 1; j <= n; j++) {
        cin >> dp.at(n).at(j);
    }

    // 下の段から上へ埋める（i 段目のコマは i+1 段目の j か j+1 に進める）
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 1) {
                // 奇数段は太郎君の番：大きい方へ進める
                dp.at(i).at(j) = max(dp.at(i + 1).at(j), dp.at(i + 1).at(j + 1));
            }
            else {
                // 偶数段は次郎君の番：小さい方へ進める
                dp.at(i).at(j) = min(dp.at(i + 1).at(j), dp.at(i + 1).at(j + 1));
            }
        }
    }

    // 最初のコマは 1 段目の 1 番目にある
    cout << dp.at(1).at(1) << endl;
}
