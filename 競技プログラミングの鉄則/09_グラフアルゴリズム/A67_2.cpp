#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    void init(int n) {
        parent.assign(n + 1, -1);
        size.assign(n + 1, 1);
    }

    int root(int u) {
        int x = u;
        while (parent.at(x) != -1) {
            x = parent.at(x);
        }

        return x;
    }

    bool same(int u, int v) {
        if (root(u) == root(v)) {
            return true;
        }

        return false;
    }

    void unite(int u, int v) {
        int ru = root(u);
        int rv = root(v);

        if (ru == rv) return;

        if (size.at(ru) >= size.at(rv)) {
            parent.at(rv) = ru;
            size.at(ru) += size.at(rv);
        }
        else {
            parent.at(ru) = rv;
            size.at(rv) += size.at(ru);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> tree(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        tree.at(i) = { c, a, b };
    }
    sort(tree.begin(), tree.end());

    UnionFind uf;
    uf.init(n);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int c, a, b;
        tie(c, a, b) = tree.at(i);

        if (!uf.same(a, b)) {
            ans += c;
            uf.unite(a, b);
        }
    }

    cout << ans << endl;
}

/* 改善点（変わる行だけ）

// same：比較の結果がそのまま true / false なので if はいらない
    bool same(int u, int v) {
        return root(u) == root(v);
    }

// 51行目：入っているのは全部の辺（木ではない）ので、名前は edges に（56・58・66行目も合わせて）
    vector<tuple<int, int, int>> edges(m);
*/
