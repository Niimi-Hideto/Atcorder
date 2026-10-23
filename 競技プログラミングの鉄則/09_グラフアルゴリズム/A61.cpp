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

    for (int i = 1; i <= n; i++) {
        cout << i << ": {";
        for (int j = 0; j < (int)g.at(i).size(); j++) {
            if (j == 0) {
                cout << g.at(i).at(j);
            }
            else {
                cout << ", " << g.at(i).at(j);
            }
        }
        cout << '}' << endl;
    }
}

/* ===== 改善点 =====
   1. if と else の違いは「前に ", " を付けるかどうか」だけなので、
      「2 つ目以降なら先に ", " を出す」→「値を出す」の 2 段にすれば、値を出す行は 1 つで済む（20–25 行目、A60 の空白区切りと同じ形）

            if (j >= 1) {                              // 20–25 行目
                cout << ", ";
            }
            cout << g.at(i).at(j);
*/
