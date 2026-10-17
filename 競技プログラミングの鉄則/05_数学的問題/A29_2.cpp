#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（途中）=====
   ・b を 2 進数で 1 桁ずつ見る形は覚えていた
   ・ループを i = 1 から始めていたので 0 桁目（1 の位）を見落とす。桁は 0 桁目から数える
   ・p を 2 乗していくことと、ans に掛けることが書けなかった

   for (int i = 1; i <= 30; i++) {
       if ((b >> i) & 1) {

       }
   }
*/

int main() {
    long long a, b;
    cin >> a >> b;

    const long long m = 1000000007;
    long long p = a;    // i 回目のループでは a^(2^i)（a^1 → a^2 → a^4 → a^8 → …）
    long long ans = 1;  // 掛け算の答えは 1 から始める

    // b ≤ 10^9 < 2^30 なので、0〜29 桁目の 30 桁を見れば足りる
    for (int i = 0; i < 30; i++) {
        if ((b >> i) & 1) {
            ans = ans * p % m;  // b の i 桁目が 1 なら、今の p（a^(2^i)）を掛ける
        }
        p = p * p % m;          // 使わない桁でも、次の桁のために p は毎回 2 乗する
    }

    cout << ans << endl;
}
