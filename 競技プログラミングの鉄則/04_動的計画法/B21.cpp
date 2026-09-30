#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // dp.at(l).at(r) = S の l 文字目〜r 文字目の中から作れる、最長の回文の長さ
    // 区間が空（l > r）のときは 0。0 で初期化しておけば、その場合を別に書かなくていい
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // 1文字だけの区間は、その1文字が回文
    for (int i = 1; i <= n; i++) {
        dp.at(i).at(i) = 1;
    }

    // dp[l][r] は内側の短い区間（[l+1, r-1]、[l+1, r]、[l, r-1]）を使うので、
    // A21 とは逆に、区間の長さ（r - l）を小さいほうから回す
    for (int len = 1; len <= n - 1; len++) {
        for (int l = 1; l + len <= n; l++) {
            int r = l + len;

            if (s.at(l - 1) == s.at(r - 1)) {
                // 両端が同じ文字：内側の回文の外側に1文字ずつ足して、2文字長くできる
                dp.at(l).at(r) = dp.at(l + 1).at(r - 1) + 2;
            }
            else {
                // 両端が違う文字：両方は使えないので、左端を捨てるか右端を捨てるかの良いほう
                dp.at(l).at(r) = max(dp.at(l + 1).at(r), dp.at(l).at(r - 1));
            }
        }
    }

    cout << dp.at(1).at(n) << endl;
}
