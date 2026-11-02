#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // g[x]：社員 x の直属の部下の一覧（上司 → 部下の向きだけ入れる）
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        g.at(a).push_back(i);
    }

    // dp[x]：社員 x の部下（直属の部下の、そのまた部下も全部）の人数
    vector<int> dp(n + 1);
    // 上司の番号は必ず部下より小さい（A_i ≤ i − 1）ので、番号の大きいほうから決めれば、
    // x を計算するときには、部下の dp はもう全部決まっている
    for (int x = n; x >= 1; x--) {
        for (int y : g.at(x)) {
            dp.at(x) += dp.at(y) + 1;  // 直属の部下 y の部下全員（dp[y]）と、y 本人（+1）
        }
    }

    for (int x = 1; x <= n; x++) {
        if (x >= 2) cout << " ";
        cout << dp.at(x);
    }
    cout << endl;
}
