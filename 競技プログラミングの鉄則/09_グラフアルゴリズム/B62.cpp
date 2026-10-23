#include <bits/stdc++.h>
using namespace std;

void dfs(int pos, const vector<vector<int>> &g, vector<int> &from) {
    for (int nex : g.at(pos)) {
        if (from.at(nex) == 0) {
            from.at(nex) = pos;
            dfs(nex, g, from);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    vector<int> from(n + 1, 0);
    from.at(1) = -1;
    dfs(1, g, from);

    vector<int> path;
    for (int v = n; v != -1; v = from.at(v)) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++) {
        if (i >= 1) {
            cout << " ";
        }
        cout << path.at(i);
    }
    cout << endl;
}
