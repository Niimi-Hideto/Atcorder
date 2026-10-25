#include <bits/stdc++.h>
using namespace std;

// a の b 乗を m で割った余り（A29 の繰り返し二乗法）
long long power(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    for (int i = 0; i < 30; i++) {
        if ((b >> i) & 1) {
            ans = ans * p % m;
        }
        p = p * p % m;
    }
    return ans;
}

int main() {
    long long n, r;
    cin >> n >> r;

    const long long m = 1000000007;

    long long top = 1;
    for (int i = 1; i <= n; i++) {
        top = top * i % m;
    }

    long long bottom = 1;
    for (int i = 1; i <= r; i++) {
        bottom = bottom * i % m;
    }
    for (int i = 1; i <= n - r; i++) {
        bottom = bottom * i % m;
    }

    cout << top * power(bottom, m - 2, m) % m << endl;
}
