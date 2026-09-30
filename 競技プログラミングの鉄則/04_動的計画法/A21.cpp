#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 添字 0 と n+1 は番兵（p = 0 は区間 [i, j] の中に入らないので得点にならない）
    vector<int> p(n + 2, 0), a(n + 2, 0);
    for (int k = 1; k <= n; k++) {
        cin >> p.at(k) >> a.at(k);
    }

    // 左端か右端からしか取らないので、残っているブロックは必ず連続区間 [i, j] になる
    // dp.at(i).at(j) = 残りが [i, j]（左端 i、右端 j）になった時点での得点の最大
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    dp.at(1).at(n) = 0;   // 最初は全部残っている

    // dp[i][j] を求めるには、1つ大きい区間 [i-1, j] と [i, j+1] が先に要るので、
    // 区間の長さ（j - i）を大きいほうから回す
    for (int len = n - 2; len >= 0; len--) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;

            // 左端のブロック i-1 を取って [i, j] になった場合。
            // その相手 p[i-1] がまだ残っている（[i, j] の中にある）なら、相手より先に取ったので得点
            int score_left = 0;
            if (i <= p.at(i - 1) && p.at(i - 1) <= j) {
                score_left = a.at(i - 1);
            }

            // 右端のブロック j+1 を取って [i, j] になった場合
            int score_right = 0;
            if (i <= p.at(j + 1) && p.at(j + 1) <= j) {
                score_right = a.at(j + 1);
            }

            // 直前の区間が存在するほうだけ考える（i = 1 なら左から取ってきたことはない、j = n なら右も同じ）
            if (i == 1) {
                dp.at(i).at(j) = dp.at(i).at(j + 1) + score_right;
            }
            else if (j == n) {
                dp.at(i).at(j) = dp.at(i - 1).at(j) + score_left;
            }
            else {
                dp.at(i).at(j) = max(dp.at(i - 1).at(j) + score_left, dp.at(i).at(j + 1) + score_right);
            }
        }
    }

    // 最後の1個を取るときは、相手はもう取られているので得点にならない。
    // だから「残り1個」の状態 dp[k][k] の最大が答え
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        ans = max(ans, dp.at(k).at(k));
    }
    cout << ans << endl;
}
