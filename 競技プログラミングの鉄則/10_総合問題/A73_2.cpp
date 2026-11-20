#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;


    vector<vector<pair<int, long long>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        g.at(a).push_back({ b, c * 1000000 - d });
        g.at(b).push_back({ a, c * 1000000 - d });
    }

    vector<bool> visited(n + 1);
    vector<long long> dist(n + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({ 0, 1 });

    while (!q.empty()) {
        long long cost = q.top().first;
        int pos = q.top().second;
        q.pop();

        if (visited.at(pos)) continue;

        visited.at(pos) = true;
        dist.at(pos) = cost;
        for (pair<int, long long> x : g.at(pos)) {
            if (!visited.at(x.first)) {
                q.push({ x.second + cost, x.first });
            }
        }
    }

    cout << (dist.at(n) + 999999) / 1000000 << " " << (dist.at(n) % 1000000 == 0 ? 0 : 1000000 - dist.at(n) % 1000000) << endl;
}

/* 改善点（変わる行だけ）

// ② 1000000 に名前を付ける（main の最初に置いて、14・15・39行目の 1000000 を BIG に）
    const long long BIG = 1000000;
        g.at(a).push_back({ b, c * BIG - d });
        g.at(b).push_back({ a, c * BIG - d });

// ① 39行目：先に距離を出して、「距離 × BIG − dist」で木の数。木が 0 本でも同じ式で 0 になるので場合分けがいらない
    long long len = (dist.at(n) + BIG - 1) / BIG;
    cout << len << " " << len * BIG - dist.at(n) << endl;

// ③ 11行目：a・b は頂点の番号なので int（long long が要るのは合計の dist）
        int a, b;
        long long c, d;
        cin >> a >> b >> c >> d;
*/
