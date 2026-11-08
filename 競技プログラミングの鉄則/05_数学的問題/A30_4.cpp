#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long bc, long long m) {
    long long ans = 1, p = bc;
    for (int i = 0; i <= 30; i++) {
        if (((m - 2) >> i) & 1) {
            ans = (ans * p) % m;
        }
        p = (p * p) % m;
    }

    return (a * ans) % m;
}

int main() {
    int n, r;
    cin >> n >> r;

    const long long m = 1000000007;

    //分母
    long long a = 1, b = 1, c = 1;
    for (int i = 1; i <= n; i++) {
        a = (a * i) % m;
    }
    //分子
    for (int i = 1; i <= r; i++) {
        b = (b * i) % m;
    }
    for (int i = 1; i <= (n - r); i++) {
        c = (c * i) % m;
    }
    long long bc = (b * c) % m;

    cout << (power(a, bc, m)) << endl;
}

/* ===== 改善点 =====
   1. n! は分数の上なので「分子」、r! × (n − r)! は下なので「分母」。コメントが逆（22・27 行目）

    //分子
    //分母

   2. power は「x の e 乗を m で割った余り」だけを返す形にして、指数は引数で渡す。
      A29 と同じ関数がそのまま使え、main を読むだけで「m − 2 乗を掛ける」が分かる（4–14・36 行目）

long long power(long long x, long long e, long long m) {
    long long ans = 1, p = x;
        if ((e >> i) & 1) {
    return ans;
}

    cout << a * power(bc, m - 2, m) % m << endl;
*/
