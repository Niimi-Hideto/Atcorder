#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    const long long m = 1000000007;

    long long ans = 1, p = a;
    for (int i = 0; i <= 30; i++) {
        if ((b >> i) & 1) {
            ans = (ans * p) % m;
        }
        p = (p * p) % m;
    }

    cout << (ans % m) << endl;
}

/* ===== 改善点 =====
   1. ans は掛けるたびに % m を取っているので、もう m 未満。出力でもう一度 % m しなくていい（18 行目）

    cout << ans << endl;
*/

