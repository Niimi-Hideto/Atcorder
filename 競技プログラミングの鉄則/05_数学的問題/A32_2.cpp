#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<bool> dp(n + 1);
    for (int i = min(a, b); i <= n; i++) {
        if (i >= a && dp.at(i - a) == false) {
            dp.at(i) = true;
        }
        if (i >= b && dp.at(i - b) == false) {
            dp.at(i) = true;
        }
    }
    cout << (dp.at(n) ? "First" : "Second") << endl;
}

/* ===== 改善点 =====
   1. A < B なので min(a, b) は必ず a。a から始めると 10 行目の i >= a はいつも true になる。
      0 から回せば「i が A 未満なら取れないので負け」が 10・13 行目の範囲チェックでそのまま表される（9 行目）

   for (int i = 0; i <= n; i++) {   // 9 行目
*/
