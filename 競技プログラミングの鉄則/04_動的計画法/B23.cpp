#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
    }

    // dist.at(i).at(j)：都市 i から都市 j までの直線距離
    vector<vector<double>> dist(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dx = x.at(i) - x.at(j);
            double dy = y.at(i) - y.at(j);
            dist.at(i).at(j) = sqrt(dx * dx + dy * dy);
        }
    }

    // 1 周して戻るので、どこから出発しても同じ。都市 0 から出発すると決める
    // dp.at(s).at(v)：都市 0 から出発して、訪れた都市の集合が s、今いる都市が v のときの最短距離
    double INF = 1e18;
    int full = (1 << n) - 1;  // 全部の都市を訪れた集合
    vector<vector<double>> dp(full + 1, vector<double>(n, INF));
    dp.at(1).at(0) = 0;  // 都市 0 だけ訪れて（集合 = 1）、都市 0 にいる

    // 集合 s は、訪れる都市が増える一方なので、小さい数から順に回せばよい（s | (1 << u) は必ず s より大きい）
    for (int s = 0; s <= full; s++) {
        for (int v = 0; v < n; v++) {
            if (dp.at(s).at(v) == INF) {
                continue;  // この状態にはまだたどり着けない
            }
            // 次に、まだ訪れていない都市 u へ移動する（配る形）
            for (int u = 0; u < n; u++) {
                if ((s >> u) & 1) {
                    continue;  // u はもう訪れた
                }
                int t = s | (1 << u);  // u を訪れた集合に足す
                dp.at(t).at(u) = min(dp.at(t).at(u), dp.at(s).at(v) + dist.at(v).at(u));
            }
        }
    }

    // 全部訪れたあと、今いる都市 v から出発地点 0 へ戻る
    double ans = INF;
    for (int v = 0; v < n; v++) {
        ans = min(ans, dp.at(full).at(v) + dist.at(v).at(0));
    }
    cout << fixed << setprecision(10) << ans << endl;
}
