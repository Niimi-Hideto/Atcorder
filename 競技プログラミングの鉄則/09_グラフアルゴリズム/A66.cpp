#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;  // par[x]：x の親（1 つ上の頂点）。親がいない（x が根）なら -1
    vector<int> siz;  // siz[x]：x が根のとき、そのグループの頂点数

    // n 頂点の Union-Find を作る。最初は全員がひとりぼっちのグループ
    void init(int n) {
        par.assign(n + 1, -1);
        siz.assign(n + 1, 1);
    }

    // x の根（グループの代表）を返す。親をたどって、親がいない頂点まで進む
    int root(int x) {
        while (par.at(x) != -1) {
            x = par.at(x);
        }
        return x;
    }

    // u のグループと v のグループを 1 つにつなぐ
    void unite(int u, int v) {
        int ru = root(u);
        int rv = root(v);
        if (ru == rv) return;  // もう同じグループ

        // 小さいグループの根を、大きいグループの根の下につなぐ（木が高くなりにくい）
        if (siz.at(ru) < siz.at(rv)) {
            par.at(ru) = rv;
            siz.at(rv) += siz.at(ru);
        }
        else {
            par.at(rv) = ru;
            siz.at(ru) += siz.at(rv);
        }
    }

    // u と v が同じグループか（根が同じなら同じグループ）
    bool same(int u, int v) {
        return root(u) == root(v);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf;
    uf.init(n);

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 1) {
            uf.unite(u, v);
        }
        else {
            cout << (uf.same(u, v) ? "Yes" : "No") << endl;
        }
    }
}
