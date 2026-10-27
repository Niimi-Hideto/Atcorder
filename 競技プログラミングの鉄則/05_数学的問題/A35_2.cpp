#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> a.at(n - 1).at(i);
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (i % 2 == 1) {
                a.at(i).at(j) = min(a.at(i + 1).at(j), a.at(i + 1).at(j + 1));
            }
            else {
                a.at(i).at(j) = max(a.at(i + 1).at(j), a.at(i + 1).at(j + 1));
            }
        }
    }
    cout << a.at(0).at(0) << endl;
}

/* ===== 改善点 =====
   1. a には最初は入力、途中からは「そこから両者が最善を尽くしたときのスコア」が入り、中身が途中で変わる。
      表の名前は dp にすると何が入っているか分かりやすい（8・10・16・19・23 行目の a を dp に）

    vector<vector<int>> dp(n, vector<int>(n));        // 8 行目
*/
