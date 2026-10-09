#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p.at(i) >> a.at(i);
    }

    // dp.at(i).at(j)：残りのブロックが [i, j] になった時点での得点の最大
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp.at(1).at(n) = 0;  // 最初は全部残っている

    // 区間の長さ len = j − i を大きいほうから（1 個多く残っている区間が先に埋まる）
    for (int len = n - 2; len >= 0; len--) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;

            // 直前が [i − 1, j]：左端のブロック i − 1 を取った
            int fromleft = 0;
            if (i >= 2) {
                int score = 0;
                if (i <= p.at(i - 1) && p.at(i - 1) <= j) {
                    score = a.at(i - 1);  // 相手 P がまだ [i, j] に残っている＝先に取った
                }
                fromleft = dp.at(i - 1).at(j) + score;
            }

            // 直前が [i, j + 1]：右端のブロック j + 1 を取った
            int fromright = 0;
            if (j <= n - 1) {
                int score = 0;
                if (i <= p.at(j + 1) && p.at(j + 1) <= j) {
                    score = a.at(j + 1);
                }
                fromright = dp.at(i).at(j + 1) + score;
            }

            dp.at(i).at(j) = max(fromleft, fromright);
        }
    }

    // 最後の 1 個は相手がもう取られているので得点にならない。残り 1 個の状態の最大が答え
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp.at(i).at(i));
    }
    cout << ans << endl;
}
