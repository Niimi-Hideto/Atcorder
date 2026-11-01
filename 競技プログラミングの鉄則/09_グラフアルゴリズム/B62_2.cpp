#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<pair<bool, int>>& visited, const vector<vector<int>>& graf) {
    visited.at(i).first = true;

    for (int x : graf.at(i)) {
        if (visited.at(x).first == false) {
            visited.at(x).second = i;
            dfs(x, visited, graf);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n + 1);
    vector<pair<bool, int>> visited(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        graf.at(a).push_back(b);
        graf.at(b).push_back(a);
    }

    dfs(1, visited, graf);

    vector<int> ans;
    for (int i = n; ; i = visited.at(i).second) {
        ans.push_back(i);

        if (i == 1) {
            break;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans.at(i);
        if (i != (int)ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

/* ===== 改善点 =====
   1. visited の second は「来た場所」なのに名前が visited で、.first / .second が何かも覚える必要がある。
      vector<bool> visited と vector<int> from の 2 つに分ける（4–5・8–9・20 行目）

        void dfs(int i, vector<bool>& visited, vector<int>& from, const vector<vector<int>>& graf) {   // 4 行目
            visited.at(i) = true;                                                                  // 5 行目
                if (visited.at(x) == false) {                                                      // 8 行目
                    from.at(x) = i;                                                                // 9 行目
                    dfs(x, visited, from, graf);                                                   // 10 行目
        vector<bool> visited(n + 1);                                                               // 20 行目
        vector<int> from(n + 1);
        dfs(1, visited, from, graf);                                                               // 29 行目

      ※ from が 0 なら「まだ来ていない」なので visited なしで from だけにもできる（from.at(1) = -1 にしておく）

   2. 頂点 1 の来た場所は誰も書き換えないので 0 のまま。「来た場所がなくなったら終わる」を for の条件に書けば
      if と break がいらない（32–38 行目）

        for (int i = n; i != 0; i = from.at(i)) {
            ans.push_back(i);
        }
*/
