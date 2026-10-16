#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<long long> pre_a(n * 2 + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    for (int i = 1; i <= n * 2; i++) {
        int j = i;
        if (j > n && j != 2 * n) {
            j %= n;
        }
        else if (j == 2 * n) {
            j = n;
        }
        pre_a.at(i) = pre_a.at(i - 1) + a.at(j);
    }
    int s = 1;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int c;
            cin >> c;

            s += c;
            if (s > n && s != 2 * n) {
                s = s % n;
            }
            else if (s == 2 * n) {
                s = n;
            }
        }
        else {
            int l, r;
            cin >> l >> r;

            cout << pre_a.at(r + s - 1) - pre_a.at(l + s - 2) << endl;
        }
    }
}

/* ===== 改善点 =====
   1. 「% n で 0 になる場合」を 2 * n のときだけ if で特別扱いしている（15〜20・33〜38 行目）。
      1〜n の番号を「n の次は 1」と回すなら、一度 1 を引いて 0 始まりにしてから % n し、最後に 1 足して戻す。
      0 になる場合が出てこないので if が要らない

   int j = (i - 1) % n + 1;   // 14〜20 行目：1〜2n を 1〜n に
   s = (s - 1) % n + 1;       // 33〜38 行目：s を 1〜n に保つ

   （別の形）ずれを最初から 0〜n−1 で持てば % n の 1 行で済む
   int crt = 0;
   crt = (crt + c) % n;
   cout << pre_a.at(r + crt) - pre_a.at(l + crt - 1) << endl;
*/
