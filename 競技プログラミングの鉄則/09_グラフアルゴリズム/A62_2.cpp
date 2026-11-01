#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool>& visited, vector<vector<int>>& graf) {
    visited.at(i) = true;

    for (int x : graf.at(i)) {
        if (visited.at(x) == false) {
            dfs(x, visited, graf);
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n + 1);
    vector<bool> visited(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        graf.at(a).push_back(b);
        graf.at(b).push_back(a);
    }

    dfs(1, visited, graf);

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (visited.at(i) == false) {
            ok = false;
        }
    }

    cout << (ok ? "The graph is connected." : "The graph is not connected.") << endl;
}

/* ===== 改善点 =====
   1. graf は dfs の中で書き換えないので const を付ける。うっかり書き換えるとコンパイルエラーで気づける（4 行目）

        void dfs(int i, vector<bool>& visited, const vector<vector<int>>& graf) {

   2. void の関数は最後の } で自動で終わるので return; はいらない（12 行目を消す）
*/
