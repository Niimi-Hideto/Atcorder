#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n, h;
        cin >> n >> h;

        int lo = h, hi = h, pre = 0;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int t, l, u;
            cin >> t >> l >> u;

            if (lo - (t - pre) > u || hi + (t - pre) < l) {
                ok = false;
            }
            lo = max(lo - (t - pre), l);
            hi = min(hi + (t - pre), u);

            pre = t;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}

/* ===== 改善点 =====
   1. 内側の t（時刻）が外側の t（テストケース数）を隠していて、どちらの t か迷う。
      時刻は ti にする（time は std::time と被るので避ける）
   2. 経過時間 t - pre を4回計算しているので、変数 dt にまとめる

   int ti, l, u;
   cin >> ti >> l >> u;
   int dt = ti - pre;
   if (lo - dt > u || hi + dt < l) {
   lo = max(lo - dt, l);
   hi = min(hi + dt, u);
   pre = ti;

   ※ hi + dt は最大 2×10^9 で int（約 2.147×10^9）に収まるので、int のままでよい
*/
