#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cap;
    cin >> n >> cap;

    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w.at(i) >> v.at(i);
    }

    long long INF = 100000000000000LL;
    vector<vector<long long>> dp(n + 1, vector<long long>(100000 + 1, INF));
    dp.at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100000; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);

            if (j >= v.at(i)) {
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i - 1).at(j - v.at(i)) + w.at(i));
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 100000; j++) {
        if (dp.at(n).at(j) <= cap) {
            ans = max(ans, j);
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 価値の合計の上限 100000 が 3 か所（14・18・28 行目）に直接書かれている。
      名前を付けると意味が読め、変えるときも 1 か所で済む

   int maxv = 100000;                                                   // 100 品 × 1000
   vector<vector<long long>> dp(n + 1, vector<long long>(maxv + 1, INF));  // 14 行目
   for (int j = 0; j <= maxv; j++) {                                    // 18・28 行目
*/
