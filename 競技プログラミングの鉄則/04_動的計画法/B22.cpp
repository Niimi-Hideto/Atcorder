// B22：A16「Dungeon 1」を配る遷移形式で実装する応用問題（提出先は A16）
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a.at(i);
    }
    for (int i = 3; i <= n; i++) {
        cin >> b.at(i);
    }

    int INF = 10000000;
    vector<int> dp(n + 1, INF);
    dp.at(1) = 0;
    for (int i = 1; i < n; i++) {
        dp.at(i + 1) = min(dp.at(i + 1), dp.at(i) + a.at(i + 1));
        if (i == n - 1) break;
        dp.at(i + 2) = min(dp.at(i + 2), dp.at(i) + b.at(i + 2));
    }
    cout << dp.at(n) << endl;
}

/* ===== 改善点 =====
   1. 答えの最大は 99999 本 × 100 分 ≈ 10^7 で、INF = 10^7 とほぼ同じ。正当な値と絶対に被らないよう余裕を持たせる
   2. やりたいのは「i + 2 が範囲内のときだけ渡す」なので、break ではなく範囲そのものを条件に書く

   int INF = 1000000000;                                                  // 17 行目
   if (i + 2 <= n) {                                                       // 22〜23 行目
       dp.at(i + 2) = min(dp.at(i + 2), dp.at(i) + b.at(i + 2));
   }
*/
