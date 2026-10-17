#include <bits/stdc++.h>
using namespace std;

// a の b 乗を m で割った余り（A29 の繰り返し二乗法）
long long power(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    for (int i = 0; i < 30; i++) {
        if ((b >> i) & 1) {
            ans = ans * p % m;  // b の i 桁目が 1 なら、今の p を掛ける
        }
        p = p * p % m;          // p を a^1 → a^2 → a^4 → … と 2 乗していく
    }
    return ans;
}

// a ÷ b を m で割った余り（m が素数なら、b で割る ＝ b の m − 2 乗を掛ける）
long long division(long long a, long long b, long long m) {
    return a * power(b, m - 2, m) % m;
}

int main() {
    int n, r;
    cin >> n >> r;

    const long long m = 1000000007;

    // 分子 n!（掛け算なので毎回余りを取ってよい）
    long long top = 1;
    for (int i = 1; i <= n; i++) {
        top = top * i % m;
    }

    // 分母 r! × (n − r)!（まとめて 1 つにしておけば、割るのは 1 回で済む）
    long long bottom = 1;
    for (int i = 1; i <= r; i++) {
        bottom = bottom * i % m;
    }
    for (int i = 1; i <= n - r; i++) {
        bottom = bottom * i % m;
    }

    cout << division(top, bottom, m) << endl;
}
