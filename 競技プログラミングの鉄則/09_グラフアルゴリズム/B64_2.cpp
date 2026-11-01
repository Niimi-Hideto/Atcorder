#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g.at(a).push_back({ c, b });
        g.at(b).push_back({ c, a });
    }

    long long INF = (1LL << 60);
    vector<long long> dst(n + 1, INF);
    vector<int> visited(n + 1);
    vector<int> from(n + 1, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    dst.at(1) = 0;
    q.push({ 0, 1 });

    while (!q.empty()) {
        int pos = q.top().second;
        long long d = q.top().first;
        q.pop();

        if (visited.at(pos) == true) continue;
        visited.at(pos) = true;

        for (pair<long long, int> x : g.at(pos)) {
            if (d + x.first < dst.at(x.second)) {
                from.at(x.second) = pos;
                dst.at(x.second) = d + x.first;
                q.push({ dst.at(x.second), x.second });
            }
        }
    }

    vector<int> ans;
    for (int i = n; i != 0; i = from.at(i)) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans.at(i);
        if (i != (int)ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

/* ===== 改善点 =====
   1. INF はあとで変えない値なので const を付ける（17 行目）

        const long long INF = 1LL << 60;

   2. visited は true / false しか入れないので vector<bool> にする（19 行目）

        vector<bool> visited(n + 1);
*/
