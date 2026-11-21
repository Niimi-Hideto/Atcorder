#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t.at(i) >> d.at(i);
    }

    // （ミス）ここに何も書いておらず、入力の順のままDPしていた
    // ↓ 追加：締切 d の早い順に並べ替える（(d, t) の pair にして sort し、t と d に戻す）
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p.at(i) = { d.at(i), t.at(i) };
    }
    sort(p.begin() + 1, p.end());
    for (int i = 1; i <= n; i++) {
        d.at(i) = p.at(i).first;
        t.at(i) = p.at(i).second;
    }

    vector<vector<int>> dp(n + 1, vector<int>(1440 + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1440; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            // if (t.at(i) <= j && d.at(i) >= j + t.at(i)) {
            if (t.at(i) <= j && j <= d.at(i)) {
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - t.at(i)) + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 1440; i++) {
        ans = max(ans, dp.at(n).at(i));
    }
    cout << ans << endl;
}
