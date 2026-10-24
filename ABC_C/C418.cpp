#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    vector<long long> pre_a(n + 1);
    for (int i = 1; i <= n; i++) {
        pre_a.at(i) = pre_a.at(i - 1) + a.at(i);
    }

    for (int query = 0; query < q; query++) {
        long long b;
        cin >> b;

        auto itr = lower_bound(a.begin(), a.end(), b);
        if (itr == a.end()) {
            cout << -1 << endl;
            continue;
        }

        int pos = itr - a.begin();
        long long ans = pre_a.at(pos - 1) + ((b - 1) * (n - pos)) + b;

        cout << ans << endl;
    }
}

/* ===== 改善点 =====
   1. a.at(0) は使わない 0 なので、ソートの範囲に入れない。A_i ≥ 1 なのでたまたま困らないだけ（13 行目）

    sort(a.begin() + 1, a.end());                      // 13 行目

   2. 「b 個以上あるフレーバーからは b − 1 個ずつ、小さいフレーバーは全部渡される。その合計より 1 個多く宣言する」
      という考え方がそのまま見える形にする（30 行目）

        long long ans = pre_a.at(pos - 1) + (b - 1) * (n - pos + 1) + 1;   // 30 行目

   3. 和は最大 3×10^5 × 10^6 = 3×10^11 で int を超える（最初の WA）。書き始める前に合計・掛け算の最大を見積もる
*/
