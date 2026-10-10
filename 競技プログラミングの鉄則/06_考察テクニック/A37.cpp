#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, b;
    cin >> n >> m >> b;

    vector<int> a(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> c.at(i);
    }

    long long ans = 0;
    for (int x : a) {
        ans += x * m;
    }
    for (int x : c) {
        ans += x * n;
    }
    ans += b * n * m;

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. A の合計と C の合計を先に出しておくと、「何が何回足されるか」が 1 行の式で読める（16〜23 行目）

   long long sa = 0, sc = 0;
   for (int x : a) sa += x;
   for (int x : c) sc += x;
   long long ans = sa * m + b * n * m + sc * n;  // A_i は M 回、B は N × M 回、C_j は N 回
*/
