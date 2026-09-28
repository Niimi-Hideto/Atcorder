#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> w(n + 1);
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w.at(i) >> v.at(i);
    }

    // 行 i   ＝ 品物 i まで選ぶか決めた（1つずつ決めていく順番の進み具合）
    // 列 j   ＝ 重さの合計（この先の判断に必要な情報で、範囲が 0〜W と小さい）
    // 中身   ＝ 価値の最大（最大化したいものは状態ではなく表の中身にする）
    // dp.at(i).at(j) = 品物 i まで決めて、重さの合計がちょうど j のときの価値の最大
    //
    // 作れない重さは「あり得ないほど小さい値」にしておく。
    // そこから + v しても小さいままなので max で自然に負ける（0 だと作れない状態と区別できない）
    const long long NG = -1000000000000000000LL;
    vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, NG));
    dp.at(0).at(0) = 0;   // 何も選ばなければ重さ 0・価値 0

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            // 品物 i を使わない
            dp.at(i).at(j) = dp.at(i - 1).at(j);

            // 品物 i を使う（重さが足りるときだけ）。A18 の || が max になっただけ
            if (j >= w.at(i)) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - w.at(i)) + v.at(i));
            }
        }
    }

    // dp は重さ「ちょうど j」なので、重さ W「以下」の中の最大が答え
    // 価値の合計は最大 100 × 10^9 = 10^11 なので long long
    long long ans = 0;
    for (int j = 0; j <= W; j++) {
        ans = max(ans, dp.at(n).at(j));
    }
    cout << ans << endl;
}
