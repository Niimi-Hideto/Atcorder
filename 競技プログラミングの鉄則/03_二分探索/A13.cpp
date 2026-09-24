#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int tmp = a.at(i);

        auto first = a.begin() + i + 1;
        int cnt = upper_bound(first, a.end(), tmp + k) - first;
        ans += cnt;
    }

    cout << ans << endl;
}

/* ===== 本のメインの解法：しゃくとり法 O(N) =====
   r = A_i から見て差が K 以下で届く一番右の添字。相方は i+1 〜 r で、個数は r - i。
   i が右に進むと A_i + K も大きくなるので、届く右端は左に戻らない。
   → 毎回ゼロから探さず、前の r から続きを伸ばすだけでいい。
   r は全体で最大 N 回しか増えないので O(N)（二分探索版は O(N log N)）

   long long ans = 0;
   int r = 0;
   for (int i = 0; i < n - 1; i++) {
       if (r < i) r = i;                         // 右端は自分より左にならない
       while (r + 1 < n && a.at(r + 1) - a.at(i) <= k) {   // 範囲チェックを先に書く
           r++;                                  // 次の要素も届くなら伸ばす
       }
       ans += r - i;
   }
*/
