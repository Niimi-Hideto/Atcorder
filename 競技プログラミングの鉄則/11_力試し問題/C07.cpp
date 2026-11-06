#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c.at(i);
    }
    sort(c.begin(), c.end());

    vector<int> pre_c(n + 1);
    for (int i = 1; i <= n; i++) {
        pre_c.at(i) = pre_c.at(i - 1) + c.at(i);
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;

        auto it = upper_bound(pre_c.begin(), pre_c.end(), x) - pre_c.begin();
        cout << it - 1 << endl;
    }
}

/* ===== 改善点 =====
   1. upper_bound(…) − pre_c.begin() で引き算しているので、中身はイテレータではなく番号（int）。
      it だとイテレータに見えるので、番号だと分かる名前にする（25–26 行目）

        int pos = upper_bound(pre_c.begin(), pre_c.end(), x) - pre_c.begin();
        cout << pos - 1 << endl;
*/
