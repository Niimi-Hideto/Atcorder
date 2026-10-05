#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（TLE）=====
   ・1 から N まで 1 つずつ調べると N = 10^12 回で間に合わない
   ・ついでに：i が int なので、N が int の範囲を超えると i が溢れる

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
*/

int main() {
    long long n;
    cin >> n;

    long long a = n / 3;   // 3 の倍数の個数（3, 6, 9, … のうち n 以下のもの）
    long long b = n / 5;   // 5 の倍数の個数
    long long c = n / 15;  // 3 と 5 の両方で割り切れる数（15 の倍数）の個数

    // a + b だと 15 の倍数を 2 回数えているので、1 回分引く
    cout << a + b - c << endl;
}
