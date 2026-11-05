#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> p(n + 1, vector<int>(n + 1));
    int ans = 0;

    vector<int> row(n + 1), col(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p.at(i).at(j);

            if (p.at(i).at(j) != 0) {
                row.at(i) = p.at(i).at(j);
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (p.at(i).at(j) != 0) {
                col.at(j) = p.at(i).at(j);
            }
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        if (row.at(i) != i) {
            for (int j = i; j <= n; j++) {
                if (row.at(j) == i) {
                    for (int k = j; k >= i + 1; k--) {
                        swap(row.at(k), row.at(k - 1));
                        ans++;
                    }
                    break;
                }
            }
        }
        if (col.at(i) != i) {
            for (int j = i; j <= n; j++) {
                if (col.at(j) == i) {
                    for (int k = j; k >= i + 1; k--) {
                        swap(col.at(k), col.at(k - 1));
                        ans++;
                    }
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   ※ 隣どうしの swap だけで並べ替える最小回数＝転倒数（i < j で a[i] > a[j] の組の数）。
     今のコードは実際に swap して数えているので、数えた回数がそのまま転倒数になっている

   1. 転倒数は実際に swap しなくても、i < j の 2 重ループで a[i] > a[j] の組を数えれば出る。
      行と列でまったく同じ処理を 2 回書いているので、関数にして 1 か所にする（29–52 行目）

        int inversion(const vector<int>& a, int n) {   // main の上に書く
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (a.at(i) > a.at(j)) cnt++;
                }
            }
            return cnt;
        }

        cout << inversion(row, n) + inversion(col, n) << endl;   // 29–54 行目をこの 1 行に（9 行目の ans もいらない）

   2. 30・41 行目の if (… != i) はいらない。正しい位置にあれば j = i で見つかり、k のループが回らない
      （1 の形にすればこの部分ごと消える）

   3. 読み込みは 1 回のループで済む。0 でないマスで row と col を両方入れれば、21–27 行目と
      8 行目の p はいらない（12–27 行目）

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;
                if (x != 0) {
                    row.at(i) = x;
                    col.at(j) = x;
                }
            }
        }
*/
