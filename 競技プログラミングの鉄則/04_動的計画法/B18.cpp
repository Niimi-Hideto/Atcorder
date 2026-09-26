#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));
    dp.at(0).at(0) = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            bool ok = false;

            if (dp.at(i - 1).at(j)) {
                ok = true;
            }
            if (j - a.at(i) >= 0 && dp.at(i - 1).at(j - a.at(i))) {
                ok = true;
            }

            if (ok) {
                dp.at(i).at(j) = true;
            }
        }
    }

    if (!dp.at(n).at(s)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    int pos = n;
    int rest = s;

    while (true) {
        if (dp.at(pos - 1).at(rest)) {
            pos -= 1;
        }
        else {
            if (rest - a.at(pos) >= 0) {
                rest -= a.at(pos);
                ans.push_back(pos);
                pos -= 1;
            }
        }
        if (rest == 0) {
            break;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

}

/* ===== 改善点 =====
   1. else に来るのは「dp[pos][rest] は true なのに dp[pos-1][rest] は false」のとき。
      カード pos を使わないと作れないので必ず rest >= a[pos] で、if (rest - a.at(pos) >= 0) は常に true。なくても動く
   2. while (true) + 最後の if (rest == 0) break; より、ループ条件に書くと
      「残りが0になるまで戻る」という意味がそのまま出る

   while (rest > 0) {
       if (dp.at(pos - 1).at(rest)) {
           pos -= 1;
       }
       else {
           rest -= a.at(pos);
           ans.push_back(pos);
           pos -= 1;
       }
   }
*/
