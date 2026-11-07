#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = n / 2 + n % 2;
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 割り算の切り上げは (n + 1) / 2 の1回で書くのが定番。一般に a ÷ b の切り上げは (a + b - 1) / b
      （鉄則 A73 の (dist + 9999) / 10000 と同じ形）

   int ans = (n + 1) / 2;
*/
