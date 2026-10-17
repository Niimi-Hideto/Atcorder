#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p.at(i) >> a.at(i);
    }

    /* 自分で書いたもの（ループの書き方を忘れていた）
    for (int len = n - 1; len >= 1; len--) {
        for (int i = 1; len - i >= ; i++) {
            int j = len - i;
        }
    }
    */

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    // len = j - i（残っている区間の幅）。[1, n]（len = n - 1）はスタートで決まっているので n - 2 から、1 個だけ残る len = 0 まで
    for (int len = n - 2; len >= 0; len--) {
        // 右端 j = i + len が n を超えないところまで、左端 i をずらす
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;

            if (i == 1) {
                int tmp = 0;
                if (i <= p.at(j + 1) && p.at(j + 1) <= j) {
                    tmp = a.at(j + 1);
                }
                dp.at(i).at(j) = dp.at(i).at(j + 1) + tmp;
            }
            else if (j == n) {
                int tmp = 0;
                if (j >= p.at(i - 1) && p.at(i - 1) >= i) {
                    tmp = a.at(i - 1);
                }
                dp.at(i).at(j) = dp.at(i - 1).at(j) + tmp;
            }
            else {
                int tmp = 0;
                if (i <= p.at(j + 1) && p.at(j + 1) <= j) {
                    tmp = a.at(j + 1);
                }
                dp.at(i).at(j) = dp.at(i).at(j + 1) + tmp;

                tmp = 0;
                if (j >= p.at(i - 1) && p.at(i - 1) >= i) {
                    tmp = a.at(i - 1);
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j) + tmp);
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
   1. 3 つ目の場合分け（42–54 行目）は 1 つ目と 2 つ目を並べただけなので、
      「右から来られるのは j < n」「左から来られるのは i > 1」の独立した 2 つの if にすると else が消える。
      dp は 0 で初期化されていて点は 0 以上なので、最初から max で更新してよい（28–54 行目）

            if (j < n) {  // [i, j + 1] からブロック j + 1 を取った
                int tmp = 0;
                if (i <= p.at(j + 1) && p.at(j + 1) <= j) {
                    tmp = a.at(j + 1);
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i).at(j + 1) + tmp);
            }
            if (i > 1) {  // [i - 1, j] からブロック i - 1 を取った
                int tmp = 0;
                if (i <= p.at(i - 1) && p.at(i - 1) <= j) {
                    tmp = a.at(i - 1);
                }
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j) + tmp);
            }

   2. 「P が [i, j] の中にある」は小さい順に i <= p && p <= j と並べるとひと目で分かる（37・50 行目。上の 1 に反映済み）
*/
