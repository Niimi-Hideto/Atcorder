#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> num(100 + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        num.at(a)++;
    }

    long long ans = 0;
    for (long long x : num) {
        if (x < 2) {
            continue;
        }

        ans += ((x) * (x - 1) * (x - 2) / (3 * 2 * 1));
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. x が 0, 1, 2 のときは x(x−1)(x−2) のどこかが 0 になり答えはもともと 0 なので、18〜20 行目の if は要らない
   2. num の中身は「長さごとの本数」なので cnt にする。22 行目の (x) の括弧も要らない

   vector<int> cnt(100 + 1);                     // 8 行目（13 行目も同じ名前にそろえる）
   for (long long x : cnt) {                      // 17〜23 行目
       ans += x * (x - 1) * (x - 2) / 6;
   }
*/
