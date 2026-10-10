#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movie(n);
    for (int i = 0; i < n; i++) {
        cin >> movie.at(i).second >> movie.at(i).first;
    }

    sort(movie.begin(), movie.end());

    int ans = 1;
    int now = movie.at(0).first;
    for (int i = 1; i < n; i++) {
        if (movie.at(i).second >= now) {
            ans++;
            now = movie.at(i).first;
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 入力の順番（L, R）と pair の中身（R, L）が逆で分かりにくいので、いったん l, r で受け取ってから入れる（10 行目）
   2. 開始時刻は 0 以上なので、ans = 0・last_end = 0 から i = 0 で回せば 1 本目の特別扱いが要らない（15〜17 行目）。
      now は「最後に見た映画の終了時刻」なので last_end にする

   int l, r;                         // 10 行目
   cin >> l >> r;
   movie.at(i) = {r, l};             // 終了時刻で並べたいので R を first に

   int ans = 0;                      // 15〜21 行目
   int last_end = 0;
   for (int i = 0; i < n; i++) {
       if (movie.at(i).second >= last_end) {
           ans++;
           last_end = movie.at(i).first;
       }
   }
*/
