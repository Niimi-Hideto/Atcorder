#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n + 1), pre_a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
        pre_a.at(i) = pre_a.at(i - 1) + a.at(i);
    }

    long long ans = 0;
    int r = 1;
    for (int i = 1; i <= n; i++) {
        if (i > r) {
            r = i;
        }

        while (r != n && pre_a.at(r + 1) - pre_a.at(i - 1) <= k) {
            r++;
        }
        if (i == r) {
            if (pre_a.at(i) - pre_a.at(i - 1) <= k) {
                ans += r - i + 1;
            }
            else if (pre_a.at(i) - pre_a.at(i - 1) > k) {
                continue;
            }
        }
        else {
            ans += r - i + 1;
        }
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 「A_i 自体が K を超えて 1 個も買えない」場合を if で分けている（24〜34 行目）。
      r を i − 1（空の区間）まで許すと場合分けが消える。A_i > K なら r は i − 1 のまま伸びず、r − i + 1 = 0 が足される
   2. 28 行目の else if (... > k) は直前の if の反対なので else でよく、continue も要らない（1 の形なら丸ごと不要）

   int r = 0;                                                         // 15 行目（i = 1 でも空の区間から始められる）
   if (r < i - 1) {                                                   // 17〜19 行目
       r = i - 1;
   }
   while (r != n && pre_a.at(r + 1) - pre_a.at(i - 1) <= k) {         // 21〜23 行目はそのまま
       r++;
   }
   ans += r - i + 1;                                                  // 24〜34 行目
*/
