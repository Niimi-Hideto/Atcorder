#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<tuple<int, int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        g.at(a).push_back({ b, c, d });
        g.at(b).push_back({ a, c, d });
    }

    /* 自分で書いたもの（queue に入れていたのが合計距離ではなく辺 1 本の長さ c だった。
       また「合計距離が同じなら木の数が多いほう」をどこでも比べていなかった）
    const int INF = (1 << 30);
    vector<int> dist(n + 1, INF);
    vector<int> tree(n + 1);
    vector<bool> visited(n + 1);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

    visited.at(1) = true;
    dist.at(1) = 0;
    for (tuple<int, int, int> x : g.at(1)) {
        int nex, c, d;
        tie(nex, c, d) = x;
        q.push({ c, nex, d });

        dist.at(nex) = min(dist.at(nex), c);
    }

    while (!q.empty()) {
        tuple<int, int, int> e = q.top();
        q.pop();

        int c, pos, d;
        tie(c, pos, d) = e;
        if (visited.at(pos) == true) continue;
        visited.at(pos) = true;
        if (d == 1) tree.at(pos)++;

        for (tuple<int, int, int> x : g.at(pos)) {
            int nex, c, d;
            tie(nex, c, d) = x;
            if (dist.at(pos) + c < dist.at(nex)) {
                tree.at(nex) = tree.at(pos);

                dist.at(nex) = dist.at(pos) + c;
                q.push({ c, nex, d });
            }
        }
    }

    cout << dist.at(n) << " " << tree.at(n) << endl;
    */

    const int INF = (1 << 30);
    vector<int> dist(n + 1, INF);  // dist[v]：頂点 1 から v までの合計距離の最小
    vector<int> tree(n + 1);       // tree[v]：その最小の距離で行くときの、木の数の最大
    vector<bool> visited(n + 1);

    // (合計距離, −木の数, 頂点)。小さい順に取り出すので、距離が短い順 → 同じなら木が多い順
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    dist.at(1) = 0;
    q.push({ 0, 0, 1 });

    while (!q.empty()) {
        int d, t, pos;
        tie(d, t, pos) = q.top();
        q.pop();

        if (visited.at(pos) == true) continue;
        visited.at(pos) = true;

        for (tuple<int, int, int> x : g.at(pos)) {
            int nex, c, w;
            tie(nex, c, w) = x;
            int nd = dist.at(pos) + c;  // nex まで行ったときの合計距離
            int nt = tree.at(pos) + w;  // そのときの木の数

            // 距離が短くなる、または距離が同じで木が多くなるなら書き換える
            if (nd < dist.at(nex) || (nd == dist.at(nex) && nt > tree.at(nex))) {
                dist.at(nex) = nd;
                tree.at(nex) = nt;
                q.push({ nd, -nt, nex });
            }
        }
    }

    cout << dist.at(n) << " " << tree.at(n) << endl;
}

/* ===== 本の書き方（2 つの基準を 1 つの数に詰める） =====
   辺の長さを「C × 10000（木があれば − 1）」にして、ふつうのダイクストラ法で解く。
   道が通る辺は最大 N − 1 = 7999 本なので、木を全部引いても 10000（距離 1 ぶん）より小さい
   → まず距離で比べて、距離が同じときだけ木の数で差がつく。
   合計は最大で約 8000 × 100 × 10000 = 8×10^9 で int に入らないので long long。

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> g(n + 1);  // (行き先, 詰めた長さ)
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        long long cost = 10000LL * c - d;  // 木があれば 1 だけ短くする
        g.at(a).push_back({ b, cost });
        g.at(b).push_back({ a, cost });
    }

    const long long INF = 1LL << 60;
    vector<long long> dist(n + 1, INF);
    vector<bool> visited(n + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    dist.at(1) = 0;
    q.push({ 0, 1 });

    while (!q.empty()) {
        int pos = q.top().second;
        q.pop();

        if (visited.at(pos) == true) continue;
        visited.at(pos) = true;

        for (pair<int, long long> x : g.at(pos)) {
            int nex = x.first;
            long long cost = x.second;
            if (dist.at(pos) + cost < dist.at(nex)) {
                dist.at(nex) = dist.at(pos) + cost;
                q.push({ dist.at(nex), nex });
            }
        }
    }

    // dist[n] ＝ 距離 × 10000 − 木の数 なので、
    // 距離は 10000 で割って切り上げ、木の数は 距離 × 10000 との差
    long long distance = (dist.at(n) + 9999) / 10000;
    long long trees = distance * 10000 - dist.at(n);
    cout << distance << " " << trees << endl;
}
*/
