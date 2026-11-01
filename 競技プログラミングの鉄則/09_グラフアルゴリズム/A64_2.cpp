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
    visited.at(1) = true;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    for (pair<long long, int> x : g.at(1)) {
        q.push(x);

        dst.at(x.second) = x.first;
    }

    while (!q.empty()) {
        int pos = q.top().second;
        long long omomi = q.top().first;
        q.pop();

        if (visited.at(pos) == true) continue;
        visited.at(pos) = true;

        for (pair<long long, int> x : g.at(pos)) {
            dst.at(x.second) = min(dst.at(x.second), omomi + x.first);
            q.push({ dst.at(x.second), x.second });
        }
    }

    dst.at(1) = 0;
    for (int i = 1; i <= n; i++) {
        cout << (dst.at(i) == INF ? -1 : dst.at(i)) << endl;
    }
}

/* ===== 改善点 =====
   1. スタートは「距離 0 で queue に入れる」だけにすれば、隣を入れるのは普通のループがやってくれる。
      今は頂点 1 に戻る辺で dst.at(1) が 0 でない値に書き換わり、43 行目で直している（20–27・43 行目）

        dst.at(1) = 0;                                 // 20–27 行目をこの 2 行に
        q.push({ 0, 1 });
                                                       // 43 行目を消す

   2. 短くなったときだけ書き換えて push する。「短くなったときだけ」という意味がコードに出る
      （push は合計 2M 回までなので速さは変わらない）（38–39 行目）

            if (d + x.first < dst.at(x.second)) {
                dst.at(x.second) = d + x.first;
                q.push({ dst.at(x.second), x.second });
            }

   3. omomi の中身は辺の重みではなく、頂点 1 から pos までの距離なので d にする（31・38 行目）

        long long d = q.top().first;                   // 31 行目
*/
