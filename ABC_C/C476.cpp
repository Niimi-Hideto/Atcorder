#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> mx;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (i < 3) {
            mx.insert(tmp);
        }
        else {
            mx.insert(tmp);
            mx.erase(begin(mx));
        }
        if (i >= 2) {
            cout << *begin(mx) << endl;
        }
    }
}

/* ===== 改善版（今の知識範囲での書き方）=====

   直した点
   1. mx.insert(tmp) が if と else の両方にあった。どちらの場合もやる処理なので
      外に出せる。残る違いは「捨てるかどうか」だけ
   2. その結果、i < 3 という添字による特別扱いが消える。判定が
      「集合のサイズが3を超えたか」になり、本当に気にしていることが
      そのまま条件になる。添字で場合分けすると「3は含む？含まない？」と
      毎回考える必要があるが、サイズで見れば迷いようがない
   3. begin(mx) より mx.begin() のほうが一般的（どちらも動く）

   今回ハマった点（言語仕様）
     multiset の erase は渡すものによって消える数が違う
       mx.erase(値)       … その値を全部消す
       mx.erase(イテレータ) … 1個だけ消す
     重複を持てる multiset で erase(値) を使うと一気に消える。
     1 2 1 2 3 で 1 2 3 と出たのはこれが原因。

int main() {
    int n;
    cin >> n;

    // 上位3個だけを保持する。*mx.begin() が3番目に大きい値
    multiset<int> mx;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        mx.insert(tmp);
        if (mx.size() > 3) {
            mx.erase(mx.begin());   // イテレータを渡すので1個だけ消える
        }

        if (i >= 2) {
            cout << *mx.begin() << endl;
        }
    }
}

===== ここまで ===== */
