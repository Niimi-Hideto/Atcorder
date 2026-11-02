#include <bits/stdc++.h>
using namespace std;

void dfs(int pos, const vector<vector<int>>& g, vector<int>& dp, vector<bool>& visited) {
    visited.at(pos) = true;
    for (int nex : g.at(pos)) {
        if (visited.at(nex) == false) {
            dfs(nex, g, dp, visited);

            dp.at(pos) = max(dp.at(pos), dp.at(nex) + 1);
        }
    }

}

int main() {
    int n, t;
    cin >> n >> t;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    vector<int> dp(n + 1);
    vector<bool> visited(n + 1);
    dfs(t, g, dp, visited);

    for (int i = 1; i <= n; i++) {
        cout << dp.at(i);
        if (i != n) {
            cout << " ";
        }
    }
    cout << endl;
}

/* ===== 改善点（好みの範囲） =====
   1. 木には輪っかがないので、隣のうち「もう来た頂点」は来た元の頂点（親）だけ。
      visited の代わりに親を引数で渡して、親だけ飛ばせば visited がいらない（4–5・7–8・30–31 行目）
      ※ 今の visited の形は木でなくても使える

        void dfs(int pos, int parent, const vector<vector<int>>& g, vector<int>& dp) {
            for (int nex : g.at(pos)) {
                if (nex == parent) continue;  // 来た元の頂点（親）にだけは戻らない

                dfs(nex, pos, g, dp);         // nex から見ると、親は今いる pos

                dp.at(pos) = max(dp.at(pos), dp.at(nex) + 1);
            }
        }

        dfs(t, 0, g, dp);                     // 31 行目（30 行目の visited は消す）。社長には親がいないので 0
*/
