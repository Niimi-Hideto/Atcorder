#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int r = 0;
    long long ans = 0;
    int sum = a.at(0);
    for (int i = 0; i < n; i++) {
        if (i > r) {
            r = i;
            if (a.at(i) <= k) {
                sum = a.at(i);
            }
            else {
                sum = 0;
            }
        }

        while (r + 1 < n && sum + a.at(r + 1) <= k) {
            sum += a.at(r + 1);
            r++;
        }

        if (a.at(i) <= k) {
            sum -= a.at(i);
            ans += r - i + 1;
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 閉区間 [i, r] だと「1 個も買えない（空の区間）」を表せないので、a.at(i) > k の場合分けが
      2 か所（19〜24 行目・32〜35 行目）に散り、15 行目の初期化も別になっている。
      半開区間 [i, r)（r ＝ 最初に入らない位置）で持つと、空の区間は r == i で表せて場合分けが消える

   int sum = 0;                                      // 15 行目
   if (r < i) {                                      // 17〜25 行目
       r = i;
       sum = 0;
   }
   while (r < n && sum + a.at(r) <= k) {            // 27〜30 行目
       sum += a.at(r);
       r++;
   }
   ans += r - i;                                     // 32〜35 行目
   if (r > i) {
       sum -= a.at(i);
   }
*/
