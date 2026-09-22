#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) tmp = -1;

        pre.at(i) = pre.at(i - 1) + tmp;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        if (pre.at(r) - pre.at(l - 1) > 0) {
            cout << "win" << endl;
        }
        else if (pre.at(r) - pre.at(l - 1) == 0) {
            cout << "draw" << endl;
        }
        else {
            cout << "lose" << endl;
        }
    }
}

/* ===== 改善点 =====
   区間の合計を2回計算しているので、変数に入れてから判定する

   int d = pre.at(r) - pre.at(l - 1);   // アタリ − ハズレ
   if (d > 0) {
   else if (d == 0) {
*/
