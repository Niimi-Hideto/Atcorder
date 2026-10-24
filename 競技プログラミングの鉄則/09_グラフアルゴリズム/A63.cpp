#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> visited(n + 1, -1);
    visited.at(1) = 1;
    queue<int> q;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        g.at(a).push_back(b);
        g.at(b).push_back(a);

        if (a == 1 && visited.at(b) == -1) {
            visited.at(b) = 1;
            q.push(b);
        }
        else if (b == 1 && visited.at(a) == -1) {
            visited.at(a) = 1;
            q.push(a);
        }
    }

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (int x : g.at(pos)) {
            if (visited.at(x) == -1) {
                visited.at(x) = visited.at(pos) + 1;
                q.push(x);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (i == 1 ? 0 : visited.at(i)) << endl;
    }
}

/* ===== 改善点 =====
   1. スタートは「頂点 1 の距離を 0 にして queue に入れる」だけでいい。
      while の 1 回目で頂点 1 の隣に 0 + 1 = 1 が入るので、入力中に頂点 1 の隣を先に入れる処理（20–27 行目）も、
      出力で頂点 1 だけ 0 に直す処理（43 行目）もいらない。
      「グラフを全部作る → スタートを queue に入れる → while で広げる」の順に分ける（本の解答の形）
   2. 中身は「来たかどうか」ではなく頂点 1 からの距離なので、名前は dist にする（8 行目）

    vector<int> dist(n + 1, -1);                       // 8 行目
    dist.at(1) = 0;                                    // 9 行目
    q.push(1);                                         // 10 行目のあと

                                                       // 20–27 行目は消す

        cout << dist.at(i) << endl;                    // 43 行目
                                                       // 35・36 行目の visited も dist にする
*/
