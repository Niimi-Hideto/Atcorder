#include <bits/stdc++.h>
using namespace std;

int main() {
    /* 自分で書いたもの（配るループを全部終えてから累積していたので、配る時点では
       「足場 i にたどり着ける通り数」がまだ決まっていなかった。24・30 行目の dp.at(i) は、
       いもすに書き込んだ途中の値で、通り数ではない。余り・西岸から東岸へ直接もなし）
    int n, w, l, r;
    cin >> n >> w >> l >> r;

    const long long m = 1000000007;
    vector<int> x(n + 1);
    vector<int> dp(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> x.at(i);

        if (l <= x.at(i) && x.at(i) <= r) {
            dp.at(i)++;
        }
    }
    x.push_back(w);

    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(x.begin(), x.end(), x.at(i) + l);
        if (it != x.end()) {
            auto pos = it - x.begin();
            dp.at(pos) += dp.at(i);
        }

        it = upper_bound(x.begin(), x.end(), x.at(i) + r);
        if (it != x.end()) {
            auto pos = it - x.begin();
            dp.at(pos) -= dp.at(i);
        }
    }

    vector<int> ans(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        ans.at(i) = ans.at(i - 1) + dp.at(i);
    }

    cout << ans.at(n + 1) << endl;
    */

    // ===== もらう DP ＋ 累積和（本の答えと同じ考え方） =====
    int n;
    long long w, l, r;
    cin >> n >> w >> l >> r;

    const long long m = 1000000007;

    // 地点 0 ＝ 西岸（位置 0）、地点 1〜N ＝ 足場、地点 N + 1 ＝ 東岸（位置 W）
    // こうすると、西岸・東岸も足場と同じ処理で扱える
    vector<long long> x(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> x.at(i);
    }
    x.at(0) = 0;
    x.at(n + 1) = w;

    // dp[i]  ：地点 i にたどり着ける通り数（の余り）
    // sum[i] ：dp[0] + dp[1] + … + dp[i]（累積和、の余り）
    vector<long long> dp(n + 2), sum(n + 2);
    dp.at(0) = 1;  // 西岸はスタートなので 1 通り
    sum.at(0) = 1;

    for (int i = 1; i <= n + 1; i++) {
        // 地点 i に来られるのは、位置が x[i] − R 以上、x[i] − L 以下の地点（i より西だけ）
        int lo = lower_bound(x.begin(), x.end(), x.at(i) - r) - x.begin();      // x[i] − R 以上の最初の地点
        int hi = upper_bound(x.begin(), x.end(), x.at(i) - l) - x.begin() - 1;  // x[i] − L 以下の最後の地点

        // 来られる地点 lo 〜 hi の dp の合計を、累積和の引き算 1 回で出す
        if (lo <= hi) {
            long long total = sum.at(hi);
            if (lo >= 1) total -= sum.at(lo - 1);
            dp.at(i) = (total % m + m) % m;  // 引き算でマイナスになりうるので + m してから余り
        }
        // lo > hi なら来られる地点がないので 0 のまま

        sum.at(i) = (sum.at(i - 1) + dp.at(i)) % m;
    }

    // 東岸（地点 N + 1）にたどり着ける通り数が答え
    cout << dp.at(n + 1) << endl;
}

/* ===== 配る DP ＋ いもす法（最初に考えた方針の正しい形。この問題では遠回り） =====
   「① 累積して地点 i の通り数を確定 → ② 届く範囲を二分探索 → ③ その範囲にいもすで配る」を
   1 つのループの中で交互にやる必要があり、読みにくい

int main() {
    int n;
    long long w, l, r;
    cin >> n >> w >> l >> r;

    const long long m = 1000000007;

    vector<long long> x(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> x.at(i);
    }
    x.at(0) = 0;
    x.at(n + 1) = w;

    vector<long long> dp(n + 2);
    vector<long long> imos(n + 3);
    long long cur = 0;

    for (int i = 0; i <= n + 1; i++) {
        // ① 地点 i の通り数を確定させる（i に配ってくる西の地点は、もう全部配り終わっている）
        cur = (cur + imos.at(i)) % m;
        if (i == 0) {
            dp.at(i) = 1;
        }
        else {
            dp.at(i) = cur;
        }

        // ② 地点 i から届く範囲（位置 x[i] + L 以上、x[i] + R 以下）を二分探索
        int lo = lower_bound(x.begin(), x.end(), x.at(i) + l) - x.begin();
        int hi = upper_bound(x.begin(), x.end(), x.at(i) + r) - x.begin();

        // ③ 地点 lo 〜 hi − 1 に dp[i] を配る（始まりに +、終わりの次に −）
        if (lo < hi) {
            imos.at(lo) = (imos.at(lo) + dp.at(i)) % m;
            imos.at(hi) = (imos.at(hi) - dp.at(i) + m) % m;
        }
    }

    cout << dp.at(n + 1) << endl;
}
*/
