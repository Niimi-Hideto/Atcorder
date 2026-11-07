#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> ans(n + 1);
    vector<int> tmp(n + 1);
    for (int i = 1; i <= n; i++) {
        ans.at(i) = i;
    }

    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;

        for (int j = 1; j <= k; j++) {
            tmp.at(j) = ans.at(k - j + 1) * -1;
        }
        for (int j = k + 1; j <= n; j++) {
            tmp.at(j) = ans.at(j);
        }

        ans = tmp;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans.at(i) << endl;
    }
}

/* ===== 改善点 =====
   1. tmp に作り直してから代入しなくても、ans をその場で書き換えられる。上の k 枚を reverse で逆順にしてから符号を反転すれば、
      tmp も「そのまま写すだけ」のループ（21〜23行目）も要らない。書く量が減るぶん、i と j の書き間違いのようなミスも入りにくい

   // 9行目の tmp と 18〜25行目を、次に置き換える
   reverse(ans.begin() + 1, ans.begin() + k + 1);
   for (int j = 1; j <= k; j++) {
       ans.at(j) *= -1;
   }
*/
