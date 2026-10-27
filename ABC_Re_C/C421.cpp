#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> pos;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s.at(i) == 'A') {
            pos.push_back(i + 1);
        }
    }

    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        ans += abs((2 * i) + 1 - pos.at(i));
    }
    for (int i = 1; i <= n; i++) {
        sum += abs((2 * i) - pos.at(i - 1));
    }

    ans = min(ans, sum);
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 位置は 1 始まり、ループは 1 つ目が 0 から・2 つ目が 1 からで、始まりがばらばら。
      位置を 0 始まりで持てば、左から k 番目の A の行き先は ABAB… なら 2k、BABA… なら 2k + 1 と素直に書け、
      1 つのループで両方の合計を足せる。名前も abab・baba にする（12・16–24 行目）

            pos.push_back(i);                          // 12 行目

    long long abab = 0, baba = 0;                      // 16–24 行目
    for (int k = 0; k < n; k++) {
        abab += abs(2 * k - pos.at(k));
        baba += abs(2 * k + 1 - pos.at(k));
    }
    long long ans = min(abab, baba);

   2. 最初の WA は合計を int で持っていたこと。最大は約 N²/2 ≈ 1.25×10^11 なので long long
*/
