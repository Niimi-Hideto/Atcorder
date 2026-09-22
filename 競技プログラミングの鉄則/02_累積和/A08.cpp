#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> x(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int tmp;
            cin >> tmp;

            x.at(i).at(j) = x.at(i).at(j - 1) + tmp;
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans = 0;
        for (int j = a; j <= c; j++) {
            ans += x.at(j).at(d) - x.at(j).at(b - 1);
        }
        cout << ans << endl;
    }
}

/* ===== 改善点（今の方針のまま）=====
   1. x の中身は入力の値ではなく「i 行目の 1〜j 列目の合計」なので、累積和と分かる名前にする
   2. 質問のループで j が「行」を表していて、入力のループ（j = 列）と意味が変わっている

   vector<vector<int>> row_pre(h + 1, vector<int>(w + 1));
   row_pre.at(i).at(j) = row_pre.at(i).at(j - 1) + tmp;

   for (int row = a; row <= c; row++) {
       ans += row_pre.at(row).at(d) - row_pre.at(row).at(b - 1);
   }

   ※ 本来の型は2次元累積和（縦にも累積して、1問を4回の足し引きで O(1) で答える）。復習で書く
*/
