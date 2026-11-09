#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cnt(400001);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
        cnt.at(a.at(i) + i)++;
    }

    long long ans = 0;
    for (int j = 1; j <= n; j++) {
        if (j - a.at(j) >= 1) {
            ans += cnt.at(j - a.at(j));
        }
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 今は全部の i を先に cnt に入れているので、j より後ろの i も入っている。
      i < j は「i ≥ j なら i + A_i > j − A_j」という式の性質でたまたま守られているだけ（17 行目の if は範囲外を防いでいるだけ）。
      1 回のループで「j の答えを cnt から足す → j 自身を cnt に入れる」の順にすれば、
      cnt には j より前の i だけが入り、i < j が形で保証される（鉄則 B54 の形。10–20 行目）

    long long ans = 0;
    for (int j = 1; j <= n; j++) {
        cin >> a.at(j);
        if (j - a.at(j) >= 1) {
            ans += cnt.at(j - a.at(j));
        }
        cnt.at(j + a.at(j))++;
    }
*/
