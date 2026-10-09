#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 1; i < n; i++) {
        cin >> b.at(i);
    }

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i != 1 && dp.at(i) == 0) {
            continue;
        }

        dp.at(a.at(i)) = max(dp.at(a.at(i)), dp.at(i) + 100);
        dp.at(b.at(i)) = max(dp.at(b.at(i)), dp.at(i) + 150);
    }

    cout << dp.at(n) << endl;
}

/* ===== 改善点 =====
   1. マス N はゴールでそこから動かないので、ループは i < n まで（i = n だと a.at(n) = b.at(n) = 0 を通して dp.at(0) に書き込んでいる）
   2. 0 を「たどり着けないマス」の印にすると、本当に 0 が正しい値になる問題で壊れる。
      初期値を -1 にして dp.at(1) = 0 とすれば、i != 1 の特別扱いも要らない

   vector<int> dp(n + 1, -1);       // 16 行目
   dp.at(1) = 0;
   for (int i = 1; i < n; i++) {    // 17 行目
       if (dp.at(i) == -1) {        // 18 行目
           continue;
       }
*/
