// コンテスト前に公開したコードを使用: https://github.com/Niimi-Hideto/Atcorder/blob/main/競技プログラミングの鉄則/09_グラフアルゴリズム/A64.cpp

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        g.at(a).push_back({ b, 0 });
    }
    for (int i = 1; i <= n; i++) {
        sort(g.at(i).begin(), g.at(i).end());
        for (int j = 0; j < (int)g.at(i).size(); j++) {
            if (j == 0) continue;
            g.at(i).at(j).second++;
        }
    }

    vector<long long> dist(n + 1, INF);
    vector<bool> done(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist.at(s) = 0;
    q.push({ 0, s });

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

    cout << (dist.at(t) == INF ? -1 : dist.at(t)) << endl;
}

/* ===== 改善点 =====
   1. 燃料を 1 にしたいのは先頭（番号が最小）以外なので、j = 0 を continue で飛ばさず、最初から j = 1 で回す。
      やりたいのは「燃料を 1 にする」なので、++ より = 1 のほうが意図がそのまま読める（21–24 行目）

        for (int j = 1; j < (int)g.at(i).size(); j++) {   // 21–24 行目
            g.at(i).at(j).second = 1;
        }
*/
