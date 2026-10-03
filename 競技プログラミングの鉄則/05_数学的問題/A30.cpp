#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（WA）=====
   ・17行目：% を取ったあとの数どうしで割り算しても正しくならない（割り算だけは途中で % できない）
   ・13行目：(r+1)×…×n = n!/r! なので、割るのは r! ではなく (n−r)!
   ・17行目：100000000 は 1000000007 の書き間違い

int main() {
    int n, r;
    cin >> n >> r;

    long long den = 1;
    for (int i = r + 1; i <= n; i++) {
        den = (den * i) % 1000000007;
    }
    long long wari = 1;
    for (int i = r; i > 0; i--) {
        wari = (wari * i) % 1000000007;
    }

    cout << (den / wari) % 100000000 << endl;
}
*/

// a の b 乗を m で割った余りを返す（A29 の繰り返し二乗法）
long long Power(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    for (int i = 0; i < 30; i++) {
        if ((b >> i) & 1) ans = (ans * p) % m;  // b の i 桁目が 1 なら今の p を掛ける
        p = (p * p) % m;                        // p を a^1, a^2, a^4, … と2乗していく
    }
    return ans;
}

// a ÷ b を m で割った余りを返す
// m が素数なら「b で割る」＝「b の m−2 乗を掛ける」（フェルマーの小定理）
long long Division(long long a, long long b, long long m) {
    return (a * Power(b, m - 2, m)) % m;
}

int main() {
    const long long M = 1000000007;
    long long n, r;
    cin >> n >> r;

    // 分子 a = n!
    long long a = 1;
    for (int i = 1; i <= n; i++) a = (a * i) % M;

    // 分母 b = r! × (n−r)!
    long long b = 1;
    for (int i = 1; i <= r; i++) b = (b * i) % M;
    for (int i = 1; i <= n - r; i++) b = (b * i) % M;

    // 割り算の代わりに Division を使う
    cout << Division(a, b, M) << endl;
}
