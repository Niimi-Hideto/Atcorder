#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        cin >> b.at(i);
    }

    long long ans = 0;
    for (int tmp = 0; tmp < (1 << n); tmp++) {
        bitset<20> s(tmp);

        long long sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            if (s.test(i)) {
                sum_a += a.at(i);
                sum_b += b.at(i);
            }
        }
        if (sum_b <= w) {
            ans = max(ans, sum_a);
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. bitset<20> の 20 は制約 N ≤ 20 に合わせて手で書いた数字なので、上限が違う問題で書き換え忘れると壊れる。
      (tmp >> i) & 1 なら大きさの指定が要らない（tmp を i ビット右にずらして、一番下の桁だけ残す）

   for (int tmp = 0; tmp < (1 << n); tmp++) {
       long long sum_a = 0, sum_b = 0;
       for (int i = 0; i < n; i++) {
           if ((tmp >> i) & 1) {
*/
