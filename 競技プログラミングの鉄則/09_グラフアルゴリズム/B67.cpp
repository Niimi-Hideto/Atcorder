#include <bits/stdc++.h>
using namespace std;

// A66 と同じ Union-Find
struct UnionFind {
    vector<int> par;
    vector<int> siz;

    void init(int n) {
        par.assign(n + 1, -1);
        siz.assign(n + 1, 1);
    }

    int root(int x) {
        while (par.at(x) != -1) {
            x = par.at(x);
        }
        return x;
    }

    void unite(int u, int v) {
        int ru = root(u);
        int rv = root(v);
        if (ru == rv) return;

        if (siz.at(ru) < siz.at(rv)) {
            par.at(ru) = rv;
            siz.at(rv) += siz.at(ru);
        }
        else {
            par.at(rv) = ru;
            siz.at(ru) += siz.at(rv);
        }
    }

    bool same(int u, int v) {
        return root(u) == root(v);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m + 1), b(m + 1), c(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i <= m; i++) {
        edges.push_back({ c.at(i), i });
    }
    sort(edges.rbegin(), edges.rend());

    UnionFind uf;
    uf.init(n);

    int ans = 0;  // 最大でも (N − 1) × 10^4 ≈ 10^9 なので int に収まる
    for (pair<int, int> e : edges) {
        int i = e.second;
        if (uf.same(a.at(i), b.at(i)) == false) {
            uf.unite(a.at(i), b.at(i));
            ans += c.at(i);
        }
    }

    cout << ans << endl;
}
