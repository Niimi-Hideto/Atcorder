#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    long long ans = 0, j = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (i > j) {
            j = i;
        }

        while (j != n && abs(a.at(i) - a.at(j + 1)) <= k) {
            j++;
        }

        ans += j - i;
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. A は小さい順なので a.at(j + 1) − a.at(i) は必ず 0 以上。abs は要らない（19 行目）
   2. j は添字なので long long にしなくてよい。答えの ans とは役割が違うので別の行で宣言し、
      「届く一番右」の意味で r にする（13 行目）

   long long ans = 0;                                            // 13 行目
   int r = 1;
   while (r != n && a.at(r + 1) - a.at(i) <= k) {               // 19 行目（15〜23 行目の j を r に）
       r++;
   }
*/
