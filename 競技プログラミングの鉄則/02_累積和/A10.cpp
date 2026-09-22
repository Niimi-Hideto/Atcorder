#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<int> mx_r(n + 2), mx_l(n + 2);
    for (int i = 1; i <= n; i++) {
        mx_r.at(i) = max(mx_r.at(i - 1), a.at(i));
    }
    for (int i = n; i > 0; i--) {
        mx_l.at(i) = max(mx_l.at(i + 1), a.at(i));
    }

    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        int l, r;
        cin >> l >> r;

        cout << max(mx_r.at(l - 1), mx_l.at(r + 1)) << endl;
    }
}

/* ===== 改善点 =====
   mx_r を左側（l-1 まで）、mx_l を右側（r+1 以降）に使っていて、名前と逆に読める。
   どちら側の最大かが分かる名前にする（pre = prefix = 先頭側、suf = suffix = 末尾側）

   vector<int> pre_max(n + 2), suf_max(n + 2);   // 先頭から i まで ／ i から末尾まで
   pre_max.at(i) = max(pre_max.at(i - 1), a.at(i));
   suf_max.at(i) = max(suf_max.at(i + 1), a.at(i));
   cout << max(pre_max.at(l - 1), suf_max.at(r + 1)) << endl;
*/
