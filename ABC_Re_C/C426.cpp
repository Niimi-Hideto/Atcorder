#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int latest = 0;
    vector<int> os(n + 1, 1);
    for (int test = 0; test < q; test++) {
        int x, y;
        cin >> x >> y;

        int ans = 0;
        for (int i = x; i > latest; i--) {
            os.at(y) += os.at(i);
            ans += os.at(i);;
        }
        if (x > latest) {
            latest = x;
        }
        cout << ans << endl;
    }
}

/* ===== 改善点 =====
   1. 19〜21 行目は max の 1 行で書ける
   2. 17 行目の ;; はセミコロン 1 つでよい
   3. 移したあとの os.at(i) を 0 にしておくと、「os.at(v) ＝ バージョン v の台数」がいつでも正しいままになる

   for (int i = x; i > latest; i--) {      // 15〜18 行目
       os.at(y) += os.at(i);
       ans += os.at(i);
       os.at(i) = 0;
   }
   latest = max(latest, x);                // 19〜21 行目
*/
