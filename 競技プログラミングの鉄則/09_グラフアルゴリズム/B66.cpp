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

    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    // クエリは先に全部読んでおく（あとで後ろから処理するため）
    int q;
    cin >> q;
    vector<int> t(q + 1), x(q + 1), u(q + 1), v(q + 1);
    vector<bool> cut(m + 1);  // cut[i]：路線 i がどこかで運休になるか
    for (int i = 1; i <= q; i++) {
        cin >> t.at(i);
        if (t.at(i) == 1) {
            cin >> x.at(i);
            cut.at(x.at(i)) = true;
        }
        else {
            cin >> u.at(i) >> v.at(i);
        }
    }

    // 全部のクエリが終わったあとの状態：一度も運休にならなかった路線だけつながっている
    UnionFind uf;
    uf.init(n);
    for (int i = 1; i <= m; i++) {
        if (cut.at(i) == false) {
            uf.unite(a.at(i), b.at(i));
        }
    }

    // 最後のクエリから最初へ、時間を逆にたどる
    vector<string> ans;
    for (int i = q; i >= 1; i--) {
        if (t.at(i) == 1) {
            // 前から見ると「運休」、後ろから見ると「復活」＝つなぐ
            uf.unite(a.at(x.at(i)), b.at(x.at(i)));
        }
        else {
            ans.push_back(uf.same(u.at(i), v.at(i)) ? "Yes" : "No");
        }
    }

    // 答えは後ろから集めたので、逆にして前からの順に戻す
    reverse(ans.begin(), ans.end());
    for (string s : ans) {
        cout << s << endl;
    }
}
