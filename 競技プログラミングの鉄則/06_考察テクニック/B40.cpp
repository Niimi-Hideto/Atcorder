#include <bits/stdc++.h>
using namespace std;

int C(int a) {
    return (a * (a - 1)) / 2;
}

int main() {
    int n;
    cin >> n;

    vector<long long> cnt(100);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cnt.at(a % 100)++;
    }

    long long ans = 0;
    for (int i = 1; i < 50; i++) {
        ans += (cnt.at(i) * cnt.at(100 - i));
    }
    ans += C(cnt.at(0));
    ans += C(cnt.at(50));

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. a は最大 2×10^5 なので a * (a − 1) は約 4×10^10 で int を超える（たまたま通っただけ）。
      cnt は long long なのに、関数に渡したところで int に戻っている。引数も戻り値も long long にする（4〜6 行目）

   long long C(long long a) {
       return a * (a - 1) / 2;
   }
*/
