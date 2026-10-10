#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    vector<int> max_wark(d + 1, 24);
    for (int i = 0; i < n; i++) {
        int l, r, h;
        cin >> l >> r >> h;

        for (int j = l; j <= r; j++) {
            max_wark.at(j) = min(max_wark.at(j), h);
        }
    }

    int ans = 0;
    for (int i = 1; i <= d; i++) {
        ans += max_wark.at(i);
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 「働く」は work なので、つづりは max_work。中身は「その日に働ける上限」なので limit などでも分かりやすい

   vector<int> max_work(d + 1, 24);  // 8 行目（14・20 行目も同じ名前にそろえる）
*/
