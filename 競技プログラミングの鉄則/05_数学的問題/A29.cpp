#include <bits/stdc++.h>
using namespace std;

// 繰り返し二乗法：a の b 乗を m で割った余りを返す
// b を2進数に分けると、a^b は a^1, a^2, a^4, a^8, … のうち「b の桁が1のもの」の積になる
// 例：b = 13 = 8 + 4 + 1（2進数 1101）なら a^13 = a^8 × a^4 × a^1
long long power(long long a, long long b, long long m) {
    long long p = a;     // 部品。i 回目の時点で a^(2^i)（a^1 → a^2 → a^4 → a^8 → …）
    long long ans = 1;   // 掛けると決めた部品を全部掛けたもの

    // b ≤ 10^9 < 2^30 なので 30 桁見れば足りる
    for (int i = 0; i < 30; i++) {
        int wari = (1 << i);

        // b の i 桁目が1なら、今の部品 p を答えに掛ける
        if ((b / wari) % 2 == 1) {
            ans = (ans * p) % m;
        }

        // 使うかどうかに関係なく、次の桁の部品を作るために2乗しておく
        p = (p * p) % m;
    }
    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;

    // p も ans も 10^9+7 未満だが、掛けると最大 10^18 になるので long long
    cout << power(a, b, 1000000007) << endl;
}

/* ===== 最初に書いたもの（TLE）=====
   a を b 回掛けると、b ≤ 10^9 で最大 10^9 回のループになり間に合わない

   long long ans = a;
   for (int i = 2; i <= b; i++) {
       ans *= a;
       ans %= 1000000007;
   }
*/
