#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<long long> w(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w.at(i) >> v.at(i);
    }

    // A19 と違い W が 10^9 と大きいので、重さは列にできない。
    // 代わりに価値の合計（最大 100 × 1000 = 10^5）を列にして、中身を「重さの最小」にする
    // dp.at(i).at(j) = 品物 i まで決めて、価値の合計がちょうど j のときの重さの最小（作れなければ -1）
    const int MAXV = 100 * 1000;
    vector<vector<long long>> dp(n + 1, vector<long long>(MAXV + 1, -1));
    dp.at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXV; j++) {
            // 品物 i を使わない
            dp.at(i).at(j) = dp.at(i - 1).at(j);

            // 品物 i を使う：足す元が作れる（-1 でない）ときだけ考える
            if (j >= v.at(i) && dp.at(i - 1).at(j - v.at(i)) != -1) {
                long long use = dp.at(i - 1).at(j - v.at(i)) + w.at(i);
                if (dp.at(i).at(j) == -1 || use < dp.at(i).at(j)) {
                    dp.at(i).at(j) = use;
                }
            }
        }
    }

    // 全部の品物を決め終わった dp[n] の中で、重さ W 以下で作れる一番大きい価値が答え
    int ans = 0;
    for (int j = 0; j <= MAXV; j++) {
        if (dp.at(n).at(j) != -1 && dp.at(n).at(j) <= W) {
            ans = j;
        }
    }
    cout << ans << endl;
}
