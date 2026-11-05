#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    /* 自分で書いたもの（時刻を後ろから回して、取れる問題を priority_queue から入れていく形を考えていた）
    priority_queue<pair<int, int>> td;
    for (int i = 1; i <= n; i++) {
        int t, d;
        cin >> t >> d;

        td.push({ t, d });
    }

    int ans = 0;
    int cnt = 0;
    for (int time = 1440; time > 0; time--) {
        while (time <= td.top().first) {
            //値を入れていく
        }

        cnt++;
    }
    */

    // (締切 D, かかる時間 T) を集めて、締切の早い順に並べる
    vector<pair<int, int>> problems(n);
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        problems.at(i) = { d, t };
    }
    sort(problems.begin(), problems.end());

    // dp[i][j]：締切の早い順に並べた最初の i 問から選んで解き、
    //           最後に解き終わる時刻が j 分のときの、正解数の最大
    vector<vector<int>> dp(n + 1, vector<int>(1441, 0));

    for (int i = 1; i <= n; i++) {
        int d = problems.at(i - 1).first;
        int t = problems.at(i - 1).second;

        for (int j = 0; j <= 1440; j++) {
            // 解かない：i − 1 問目までと同じ
            dp.at(i).at(j) = dp.at(i - 1).at(j);

            // 解く：時刻 j − t から t 分考えて、ちょうど時刻 j に解き終わる。締切 d までに終わるときだけ
            if (t <= j && j <= d) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - t) + 1);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 1440; j++) {
        ans = max(ans, dp.at(n).at(j));
    }
    cout << ans << endl;
}
