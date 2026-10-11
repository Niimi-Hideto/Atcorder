#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    bool ok = false;

    int tmp = -1;
    for (int i = 0; i < n; i++) {
        if (!ok && s.at(i) == 'R') {
            tmp = i;
            ok = true;
        }

        if (ok) {
            if (s.at(i) == 'S') {
                ans = max(ans, i - tmp);
                ok = false;
            }
            else if (i == n - 1) {
                ans = max(ans, i + 1 - tmp);
                ok = false;
            }
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 「雨が始まった日 tmp」を覚えて晴れの日・最終日に長さを計算すると、ok の管理と最終日の
      特別扱い（24〜27行目）が要る。「今日まで続いている雨の日数」cnt を1変数で持ち回し、
      毎日 ans を更新すれば、ok・tmp・最終日の場合分けが全部消える（ABC456 C の run 長と同じ形）

   int cnt = 0;
   for (int i = 0; i < n; i++) {
       if (s.at(i) == 'R') cnt++;
       else cnt = 0;
       ans = max(ans, cnt);
   }
*/
