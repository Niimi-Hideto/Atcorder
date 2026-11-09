#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int r_mx = 0, c_mx = 0;
    long long r_mn = 100000000000, c_mn = 100000000000;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;

        if (r_mx < r) {
            r_mx = r;
        }
        if (r_mn > r) {
            r_mn = r;
        }
        if (c_mx < c) {
            c_mx = c;
        }
        if (c_mn > c) {
            c_mn = c;
        }
    }

    cout << max(r_mx - r_mn, c_mx - c_mn) / 2 + max(r_mx - r_mn, c_mx - c_mn) % 2 << endl;
}

/* ===== 改善点 =====
   1. 座標は 10^9 以下なので全部 int でいい。最小の初期値は座標の最大 10^9 で足りる。型をそろえる（8–9 行目）

    int r_mx = 0, c_mx = 0;
    int r_mn = 1000000000, c_mn = 1000000000;

   2. if 4 つは max / min で 1 行ずつ（14–25 行目）

        r_mx = max(r_mx, r);
        r_mn = min(r_mn, r);
        c_mx = max(c_mx, c);
        c_mn = min(c_mn, c);

   3. max(…) を 2 回書かずに 1 回で名前を付け、切り上げは (a + b − 1) / b の形で (d + 1) / 2（28 行目）

    int d = max(r_mx - r_mn, c_mx - c_mn);
    cout << (d + 1) / 2 << endl;
*/