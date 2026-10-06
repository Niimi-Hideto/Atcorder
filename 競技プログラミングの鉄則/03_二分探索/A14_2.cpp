#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> c.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> d.at(i);
    }

    vector<int> ab, cd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a.at(i) + b.at(j));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cd.push_back(c.at(i) + d.at(j));
        }
    }

    sort(cd.begin(), cd.end());
    bool ok = false;

    for (int i = 0; i < n * n; i++) {
        int tmp = *lower_bound(cd.begin(), cd.end(), k - ab.at(i));
        if (ab.at(i) + tmp == k) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. 38 行目：k − ab.at(i) が cd のどの値より大きいと lower_bound は cd.end()（最後の 1 つ後ろ）を返し、
      * で読むと配列の外を読む（.at() と違って止まらず、でたらめな値になる。今回はたまたま通った）。
      あるかどうかだけ知りたいなら binary_search で true / false を直接もらう（39 行目の足し算も要らない）
   2. ab と cd は同じ二重ループで作れる（23〜32 行目を 1 つにまとめる）

   if (binary_search(cd.begin(), cd.end(), k - ab.at(i))) {   // 38〜39 行目

   // lower_bound のまま書くなら、イテレータで受け取って end() でないかを先に確かめる（&& の左が先）
   auto it = lower_bound(cd.begin(), cd.end(), k - ab.at(i)); // 38〜39 行目（別の書き方）
   if (it != cd.end() && *it == k - ab.at(i)) {

   for (int i = 0; i < n; i++) {                                // 23〜32 行目
       for (int j = 0; j < n; j++) {
           ab.push_back(a.at(i) + b.at(j));
           cd.push_back(c.at(i) + d.at(j));
       }
   }
*/
