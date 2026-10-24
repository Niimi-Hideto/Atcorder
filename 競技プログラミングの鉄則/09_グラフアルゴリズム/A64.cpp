#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g.at(a).push_back({ b, c });
        g.at(b).push_back({ a, c });
    }

    vector<long long> dist(n + 1, INF);
    vector<bool> done(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist.at(1) = 0;
    q.push({ 0, 1 });

    while (!q.empty()) {
        int pos = q.top().second;
        q.pop();

        if (done.at(pos)) {
            continue;
        }
        done.at(pos) = true;

        for (pair<int, int> e : g.at(pos)) {
            int nex = e.first;
            int cost = e.second;
            if (dist.at(nex) > dist.at(pos) + cost) {
                dist.at(nex) = dist.at(pos) + cost;
                q.push({ dist.at(nex), nex });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist.at(i) == INF) {
            cout << -1 << endl;
        }
        else {
            cout << dist.at(i) << endl;
        }
    }
}
