#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p.at(i) >> a.at(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int len = n - 1; len >= 1; len--) {
        for (int i = 1; (i + len - 1) <= n; i++) {
            int j = len + i - 1;

            if (i == 1) {
                dp.at(i).at(j) = dp.at(i).at(j + 1);
                if (p.at(j + 1) <= j + 1) {
                    dp.at(i).at(j) += a.at(j + 1);
                }
            }
            else if (j == n) {
                dp.at(i).at(j) = dp.at(i - 1).at(j);
                if (p.at(i - 1) >= i - 1) {
                    dp.at(i).at(j) += a.at(i - 1);
                }
            }
            else {
                int r = dp.at(i).at(j + 1);
                if (p.at(j + 1) <= j + 1 && p.at(j + 1) >= i) {
                    r += a.at(j + 1);
                }
                int l = dp.at(i - 1).at(j);
                if (p.at(i - 1) >= i - 1 && p.at(i - 1) <= j) {
                    l += a.at(i - 1);
                }
                dp.at(i).at(j) = max(l, r);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp.at(i).at(i));
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 点がもらえるのは「相手のブロックがまだ残っている区間 [i, j] の中にある」とき。
      <= j + 1 や >= i - 1 でも P_i ≠ i なので結果は同じだが、どちらから来ても i <= P && P <= j にそろえると意味が読める
   2. i == 1・j == n・それ以外の 3 通りに分けず、「j < n なら右から来られる」「i > 1 なら左から来られる」の
      独立した 2 つの if にして、どちらも max で更新すれば同じ処理を 2 回書かなくて済む（18–40 行目）

            if (j < n) {                               // 18–40 行目
                int score = dp.at(i).at(j + 1);
                if (i <= p.at(j + 1) && p.at(j + 1) <= j) {
                    score += a.at(j + 1);
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), score);
            }
            if (i > 1) {
                int score = dp.at(i - 1).at(j);
                if (i <= p.at(i - 1) && p.at(i - 1) <= j) {
                    score += a.at(i - 1);
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), score);
            }
*/
