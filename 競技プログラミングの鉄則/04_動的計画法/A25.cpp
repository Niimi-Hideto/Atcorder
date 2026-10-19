#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> c(h + 1);
    for (int i = 1; i <= h; i++) {
        cin >> c.at(i);
    }

    /* 自分で書いたもの（そのマスから「次に進める数」を数えて、上と左の max を取っていた）
    vector<vector<int>> dp(h + 2, vector<int>(w + 2));
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < w; j++) {
            if (c.at(i).at(j) == '#') {
                dp.at(i).at(j + 1) = -1;
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {

            if (dp.at(i).at(j) == -1) continue;

            int cnt = 0;
            if (dp.at(i).at(j + 1) != -1) {
                cnt++;
            }
            if (dp.at(i + 1).at(j) != -1) {
                cnt++;
            }

            dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1)) + cnt;
        }
    }
    cout << dp.at(h).at(w) << endl;
    */

    // dp[i][j]：(1, 1) から (i, j) まで来る方法の数。道の数は最大 3×10^16 くらいになるので long long
    vector<vector<long long>> dp(h + 1, vector<long long>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && j == 1) {
                // スタート：そこにいるだけの 1 通り
                dp.at(i).at(j) = 1;
                continue;
            }
            // (i, j) の直前は上か左。別々の道なので足し算。黒いマスからは来られないので足さない（c は 0 始まりなので j - 1）
            if (i >= 2 && c.at(i - 1).at(j - 1) == '.') {
                dp.at(i).at(j) += dp.at(i - 1).at(j);
            }
            if (j >= 2 && c.at(i).at(j - 2) == '.') {
                dp.at(i).at(j) += dp.at(i).at(j - 1);
            }
        }
    }

    cout << dp.at(h).at(w) << endl;
}
