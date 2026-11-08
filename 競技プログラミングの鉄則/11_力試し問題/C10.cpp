#include <bits/stdc++.h>
using namespace std;

int main() {
    long long w;
    cin >> w;

    const long long m = 1000000007;

    if (w == 1) {
        cout << 4 * 3 << endl;
    }
    else {
        long long p = 7, ans = 1;
        for (long long i = 0; i <= 60; i++) {
            if (((w - 1) >> i) & 1) {
                ans = (ans * p) % m;
            }
            p = (p * p) % m;
        }

        cout << 4 * 3 * ans % m << endl;
    }

}

/* ===== 改善点 =====
   1. W = 1 のとき w − 1 = 0 でビットが 1 つも立たず ans = 1 のままなので、else の中の式だけで 12 が出る。
      if (w == 1) の場合分けは要らない（10–13・23 行目を消して、中身だけ残す）

    long long p = 7, ans = 1;
    for (long long i = 0; i <= 60; i++) { … }
    cout << 4 * 3 * ans % m << endl;
*/
