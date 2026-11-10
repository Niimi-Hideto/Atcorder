#include <bits/stdc++.h>
using namespace std;

/* 自分で書いたもの（struct の名前と unite の枠まで。中身の持ち方が思い出せなかった）
struct Union_find {

    void unite() {
    }
};
*/

struct UnionFind {
    vector<int> par;  // par[x]：x の 1 つ上の親（x が根なら −1）
    vector<int> siz;  // siz[x]：x が根のとき、そのグループの頂点の数

    // 最初は全員が 1 人ずつのグループ（全員が根）
    void init(int n) {
        par.assign(n + 1, -1);
        siz.assign(n + 1, 1);
    }

    // x の根を返す（親が −1 になるまで上にたどる）
    int root(int x) {
        while (par.at(x) != -1) {
            x = par.at(x);
        }
        return x;
    }

    // u のグループと v のグループをつなぐ
    void unite(int u, int v) {
        int ru = root(u), rv = root(v);
        if (ru == rv) return;  // もう同じグループなら何もしない

        // 小さいグループの根を、大きいグループの根の下につなぐ
        if (siz.at(ru) < siz.at(rv)) {
            par.at(ru) = rv;
            siz.at(rv) += siz.at(ru);
        }
        else {
            par.at(rv) = ru;
            siz.at(ru) += siz.at(rv);
        }
    }

    // u と v が同じグループか（根が同じか）
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
            if (uf.same(u, v)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}
