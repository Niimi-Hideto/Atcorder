#include <bits/stdc++.h>
using namespace std;

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

    int cnt = 0; int ans = 0;
    for (int i = 1; i <= n; i++) {

        if (cnt < (int)g.at(i).size()) {
            cnt = (int)g.at(i).size();
            ans = i;
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 使っているのは友達の人数（.size()）だけで、「誰と友達か」は使っていない。
      隣接リストは作らず、人数だけ数える vector<int> で足りる（8・13・14・20・21 行目）

    vector<int> deg(n + 1);                            // 8 行目
        deg.at(a)++;                                   // 13 行目
        deg.at(b)++;                                   // 14 行目
        if (cnt < deg.at(i)) {                         // 20 行目
            cnt = deg.at(i);                           // 21 行目

   2. 同じ型の変数は 1 つの宣言にまとめる（17 行目）

    int cnt = 0, ans = 0;                              // 17 行目
*/
