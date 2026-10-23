#include <bits/stdc++.h>
using namespace std;

void dfs(int pos, vector<vector<int>> &g, vector<bool> &visited) {
    visited.at(pos) = true;
    for (int nex : g.at(pos)) {
        if (!visited.at(nex)) {
            dfs(nex, g, visited);
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

    vector<bool> visited(n + 1, false);
    dfs(1, g, visited);

    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited.at(i)) {
            connected = false;
        }
    }

    if (connected) {
        cout << "The graph is connected." << endl;
    }
    else {
        cout << "The graph is not connected." << endl;
    }
}
