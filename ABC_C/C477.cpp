#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    string s, t;
    cin >> q >> s >> t;

    int size = (int)s.size();
    vector<int> piece;
    if (size >= t.size()) {
        for (int i = 0; i < size - (t.size() - 1); i++) {
            if (s.at(i) == t.at(0)) {
                bool ok = true;
                for (int j = 1; j < t.size(); j++) {
                    if (s.at(i + j) != t.at(j)) {
                        ok = false;
                    }
                }
                if (ok) {
                    piece.push_back(i);
                }
            }
        }
    }


    for (int test = 0; test < q; test++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        bool ok = false;
        if (r - l + 1 >= (int)t.size()) {
            if (piece.size() != 0 && lower_bound(piece.begin(), piece.end(), l) != piece.end()) {
                if (*lower_bound(piece.begin(), piece.end(), l) <= r - (int)t.size() + 1) {
                    ok = true;
                }
            }

        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}

/* ===== 改善点 =====
   1. lower_bound を2回呼んでいるので結果を変数に入れる。piece が空なら lower_bound は end() を
      返すので、piece.size() != 0 のチェックは要らない（it != end() を左に書くのは正しくできていた）
   2. t.size() は符号なしなので int と混ぜるとキャストが要る。最初に int m = t.size(); として m で書く
   3. 区間が T より短いと r - m + 1 < l になり 1 の判定で自動的に No になるので、35行目の長さチェックは不要

   int m = t.size();
   auto it = lower_bound(piece.begin(), piece.end(), l);
   if (it != piece.end() && *it <= r - m + 1) {
       ok = true;
   }
*/

/* ===== 別解：累積和（「区間の中に何個あるか」を聞かれたらこの形）=====
   cnt.at(i) = 位置 0〜i-1 のうち T の開始位置の個数。区間 [l, r - m + 1] の中の個数が1以上なら Yes

   vector<int> cnt(size + 1);
   for (int i = 0; i < size; i++) {
       cnt.at(i + 1) = cnt.at(i) + (i が T の開始位置なら 1、そうでなければ 0);
   }
   int hi = r - m + 1;
   bool ok = (hi >= l && cnt.at(hi + 1) - cnt.at(l) > 0);

   注意：区間が T より短いと hi < l になり、引き算の範囲が逆転する。hi >= l の確認が要る
*/
