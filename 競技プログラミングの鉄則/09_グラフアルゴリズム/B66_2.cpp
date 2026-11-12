#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int root(int u) {
        int nex;
        if (parent.at(u) != -1) {
            nex = root(parent.at(u));
        }
        else {
            nex = u;
        }

        return nex;
    }

    void unite(int u, int v) {
        if (same(u, v)) return;

        if (size.at(root(u)) >= size.at(root(v))) {
            size.at(root(u)) += size.at(root(v));
            parent.at(root(v)) = root(u);
        }
        else {
            size.at(root(v)) += size.at(root(u));
            parent.at(root(u)) = root(v);
        }
    }


    vector<int> parent;
    vector<int> size;

    void init(int n) {
        parent.assign(n + 1, -1);
        size.assign(n + 1, 1);
    }

    bool same(int u, int v) {
        if (root(u) == root(v)) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf;
    uf.init(n);

    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    int q;
    cin >> q;
    vector<int> type(q + 1);
    vector<pair<int, int>> query(q + 1);
    vector<bool> cut(m + 1);
    for (int i = 1; i <= q; i++) {
        cin >> type.at(i);

        if (type.at(i) == 1) {
            int x;
            cin >> x;

            cut.at(x) = true;
            query.at(i) = { x, 0 };
        }
        else {
            int u, v;
            cin >> u >> v;

            query.at(i) = { u, v };
        }
    }

    for (int i = 1; i <= m; i++) {
        if (cut.at(i)) continue;

        uf.unite(a.at(i), b.at(i));
    }

    vector<string> ans;
    for (int i = q; i >= 1; i--) {
        if (type.at(i) == 1) {
            uf.unite(a.at(query.at(i).first), b.at(query.at(i).first));
        }
        else {
            if (uf.same(query.at(i).first, query.at(i).second)) {
                ans.push_back("Yes");
            }
            else {
                ans.push_back("No");
            }
        }
    }


    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans.at(i) << endl;
    }
}

/* 改善点（変わる行だけ）

// unite：根を最初に 1 回だけ求めて、あとは ru・rv を使う（same も呼ばない）
    void unite(int u, int v) {
        int ru = root(u), rv = root(v);
        if (ru == rv) return;

        if (size.at(ru) >= size.at(rv)) {
            size.at(ru) += size.at(rv);
            parent.at(rv) = ru;
        }
        else {
            size.at(rv) += size.at(ru);
            parent.at(ru) = rv;
        }
    }

// same：比較の結果がそのまま true / false なので if はいらない
    bool same(int u, int v) {
        return root(u) == root(v);
    }
*/
