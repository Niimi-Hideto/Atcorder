#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // dp.at(l).at(r)：S の l〜r 文字目の中から（とびとびに）選んで作れる最長の回文の長さ
    // S の l 文字目は s.at(l - 1)（文字列は 0 始まり）
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // 1 文字の区間は、その 1 文字だけで長さ 1 の回文
    for (int i = 1; i <= n; i++) {
        dp.at(i).at(i) = 1;
    }

    // 区間の長さ len = r − l を小さいほうから（内側の短い区間が先に埋まる）
    for (int len = 1; len <= n - 1; len++) {
        for (int l = 1; l + len <= n; l++) {
            int r = l + len;

            if (s.at(l - 1) == s.at(r - 1)) {
                // 両端が同じ：一番外側のペアにして、内側 [l+1, r−1] の最長に 2 を足す
                // len = 1 のときの内側 dp.at(l + 1).at(l) は「空の区間」で 0 のまま
                dp.at(l).at(r) = dp.at(l + 1).at(r - 1) + 2;
            }
            else {
                // 両端が違う：左を捨てる [l+1, r] か、右を捨てる [l, r−1] の良いほう
                dp.at(l).at(r) = max(dp.at(l + 1).at(r), dp.at(l).at(r - 1));
            }
        }
    }

    cout << dp.at(1).at(n) << endl;
}
