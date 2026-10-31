#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<int> sum(10);
    for (int i = 1; i <= 9; i++) {
        sum.at(i) = sum.at(i - 1) + i;
    }

    long long ans = 0;
    for (long long i = 1; i <= n; i *= 10) {
        ans += (n / (i * 10)) * (sum.at(9) * i);

        //満杯の小箱
        int d = (n % (i * 10)) / i;
        if (d >= 1) {
            ans += sum.at((d - 1)) * i;
        }
        ans += d * (n % i + 1);
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 0 + 1 + … + (d − 1) は d * (d − 1) / 2 で出せて、d = 0 のときも 0 になるので、
      和の表も if (d >= 1) もいらない。15 行目の 45 も同じ式の d = 10（10 × 9 / 2）（8–11・15・18–21 行目）

        ans += (n / (i * 10)) * 45 * i;                // 15 行目（8–11 行目の表は消す）

        long long d = (n % (i * 10)) / i;              // 18 行目
        ans += d * (d - 1) / 2 * i;                    // 19–21 行目
*/
