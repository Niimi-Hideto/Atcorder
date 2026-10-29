#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> c(h + 1);
    for (int i = 1; i <= h; i++) {
        cin >> c.at(i);
        c.at(i) = " " + c.at(i);
    }

    vector<vector<long long>> dp(h + 1, vector<long long>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1) {
                if (c.at(i).at(j) == '#') {
                    break;
                }
                dp.at(i).at(j) = 1;
            }
            else if (j == 1) {
                if (c.at(i).at(j) == '#') {
                    dp.at(i).at(j) = 0;
                    continue;
                }
                dp.at(i).at(j) = dp.at(i - 1).at(j);
            }
            else {
                if (c.at(i - 1).at(j) != '#') {
                    dp.at(i).at(j) += dp.at(i - 1).at(j);
                }
                if (c.at(i).at(j - 1) != '#') {
                    dp.at(i).at(j) += dp.at(i).at(j - 1);
                }
            }
        }
    }
    cout << dp.at(h).at(w) << endl;
}

/* ===== 改善点 =====
   1. 1 行目・左端の列・それ以外の 3 通りに分けると、端の処理でミスが入りやすい（今回の WA も左端の列）。
      黒マスは 0 のまま・スタートだけ 1 にしておけば、前のマスが黒かを調べなくていい（足しても増えない）。
      0 行目・0 列目は 0 のままなので、端でも上と左をそのまま足せる（17–37 行目）

            if (i == 1 && j == 1) {                    // 17–37 行目
                dp.at(i).at(j) = 1;
                continue;
            }
            if (c.at(i).at(j) == '#') {
                continue;
            }
            dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i).at(j - 1);
*/
