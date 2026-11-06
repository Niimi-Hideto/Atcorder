#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, x;
    cin >> d >> x;

    vector<int> a(d + 1);
    for (int i = 2; i <= d; i++) {
        cin >> a.at(i);
    }

    vector<int> pre_x(d + 1);
    for (int i = 1; i <= d; i++) {
        pre_x.at(i) = pre_x.at(i - 1) + a.at(i);

        if (i == 1) {
            pre_x.at(i) = x;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;

        if (pre_x.at(s) == pre_x.at(t)) {
            cout << "Same" << endl;
        }
        else if (pre_x.at(s) > pre_x.at(t)) {
            cout << s << endl;
        }
        else {
            cout << t << endl;
        }
    }
}

/* ===== 改善点 =====
   1. 1 日目を「0 日目から X 上がった」と考えれば、ほかの日と同じ式で書けるので、ループの中の
      if (i == 1) はいらない（11 行目の後ろに 1 行足して、17–19 行目を消す）

        a.at(1) = x;                                   // 11 行目の後ろに足す（pre_x[1] = 0 + x = x になる）

   ※ 株価の最大は X + (D − 1) × 5000 ≈ 2×10^9 で、int の上限（約 2.1×10^9）にぎりぎり収まる
*/
