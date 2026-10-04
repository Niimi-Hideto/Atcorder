#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> right;
    vector<int> c;
    right.push_back(0);
    char tmp;
    int r = 0, l = 0;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            right.push_back(right.back());
            cin >> tmp;

            if (tmp == '(') {
                l++;
                c.push_back(1);
            }
            else {
                if (l <= r) {
                    right.back()++;
                }
                r++;
                c.push_back(-1);
            }
        }
        else {
            if (c.back() == 1) {
                l--;
                c.pop_back();
                right.pop_back();
            }
            else {
                r--;
                c.pop_back();
                right.pop_back();
            }
        }
        cout << (l == r && right.back() == 0 ? "Yes" : "No") << endl;
    }
}

/* ===== 改善点 =====
   1. 削除のときの c.pop_back() と right.pop_back() は、どちらの場合も同じなので if の外に 1 回だけ書く
   2. 使っているのは l − r だけなので、収支 bal 1 つで持つ。c には +1 / −1 が入っているので、
      削除は bal -= c.back() で済み、34〜43 行目の if が要らなくなる
   3. right は「途中でマイナスになった回数」なので bad、tmp は読んだ文字なので ch にする

   int bal = 0;                       // l, r の代わり
   if (bal <= 0) bad.back()++;        // 26〜28 行目（')' のとき、足す前に見る）
   bal += c.back();                   // 22 行目・29 行目（push_back のあと）
   else {                             // 33〜44 行目
       bal -= c.back();
       c.pop_back();
       bad.pop_back();
   }
   cout << (bal == 0 && bad.back() == 0 ? "Yes" : "No") << endl;
*/
