#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> ab(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        ab.at(i) = { a, b };
    }

    sort(ab.begin(), ab.end());
    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i > j) {
            j = i;
        }
        while (j != n) {
            if (ab.at(j + 1).first - ab.at(i).first <= k) {
                j++;
            }
            else {
                break;
            }
        }


        for (int m = i; m <= j; m++) {
            int cnt = 0;
            int min = ab.at(m).second;
            for (int n = i; n <= j; n++) {
                if (ab.at(n).second >= min && ab.at(n).second - min <= k) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 添字 0 の (0, 0) を含めて全体を sort している。値が 1 以上なのでたまたま先頭に残るが、
      0 があり得る問題だと壊れる。1 番目から並べる（16 行目）
   2. min は標準の min 関数と、n は入力の N と同じ名前。low、p などにする（35・36 行目）
   3. while は条件をまとめると A13 の形になる（23〜30 行目）

   sort(ab.begin() + 1, ab.end());     c                                     // 16 行目
   while (j + 1 <= n && ab.at(j + 1).first - ab.at(i).first <= k) {        // 23〜30 行目
       j++;
   }
   int low = ab.at(m).second;                                              // 35 行目
   for (int p = i; p <= j; p++) {                                          // 36〜40 行目
       if (low <= ab.at(p).second && ab.at(p).second <= low + k) {
           cnt++;
       }
   }
*/

/* ===== 別解（本の解き方）=====
   体力・気力とも値が 1〜100 と小さいので、範囲の左下の角 (a, b) を値で全部試す（固定して全探索）。
   ソートもしゃくとりも要らず、範囲に入るかは不等式 4 つで判定できる。100 × 100 × N = 3×10^6

   int ans = 0;
   for (int a = 1; a <= 100; a++) {
       for (int b = 1; b <= 100; b++) {
           int cnt = 0;
           for (int i = 1; i <= n; i++) {
               int x = ab.at(i).first, y = ab.at(i).second;  // 生徒 i の体力と気力
               if (a <= x && x <= a + k && b <= y && y <= b + k) {
                   cnt++;
               }
           }
           ans = max(ans, cnt);
       }
   }
*/
