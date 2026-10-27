#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp.at(i).at(i) = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (s.at(i - 1) == s.at(j - 1)) {
                dp.at(i).at(j) = dp.at(i + 1).at(j - 1) + 2;
            }
            int tmp = max(dp.at(i).at(j - 1), dp.at(i + 1).at(j));
            dp.at(i).at(j) = max(dp.at(i).at(j), tmp);
        }
    }
    cout << dp.at(1).at(n) << endl;
}

/* ===== 改善点 =====
   1. 区間は 1 始まり、文字列は 0 始まりで s.at(i - 1) と - 1 が要っている。
      読んだ直後に先頭へ 1 文字足せば、区間の番号のまま s.at(i) と書ける（7・17 行目、B38 と同じ）

    s = " " + s;                                       // 7 行目のあと
            if (s.at(i) == s.at(j)) {                  // 17 行目

   2. 両端が同じときは内側 + 2 がいつも一番大きいので、捨てる 2 通りと比べなくていい。
      if / else に分ければ tmp もいらない（17–21 行目。今の形でも答えは同じ）

            if (s.at(i) == s.at(j)) {                  // 17–21 行目
                dp.at(i).at(j) = dp.at(i + 1).at(j - 1) + 2;
            }
            else {
                dp.at(i).at(j) = max(dp.at(i).at(j - 1), dp.at(i + 1).at(j));
            }
*/
