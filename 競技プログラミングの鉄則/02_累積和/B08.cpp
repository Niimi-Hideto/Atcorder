#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> table(1500 + 1, vector<int>(1500 + 1));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        table.at(x).at(y)++;
    }

    //横累積和
    for (int i = 1; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) {
            table.at(i).at(j) += table.at(i).at(j - 1);
        }
    }
    //縦累積和
    for (int i = 1; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) {
            table.at(i).at(j) += table.at(i - 1).at(j);
        }
    }

    int q;
    cin >> q;
    for (int test = 0; test < q; test++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans = table.at(c).at(d) + table.at(a - 1).at(b - 1)
            - table.at(a - 1).at(d) - table.at(c).at(b - 1);
        cout << ans << endl;
    }
}

/* ===== 改善点 =====
   座標の上限 1500 が5回出てくるので、定数にして1箇所で管理する（APG4b 3.06 の const）

   const int M = 1500;
   vector<vector<int>> table(M + 1, vector<int>(M + 1));
   for (int i = 1; i <= M; i++) {
       for (int j = 1; j <= M; j++) {
*/
