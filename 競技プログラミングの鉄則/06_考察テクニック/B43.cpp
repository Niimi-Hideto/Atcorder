#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ans(n + 1);
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;

        ans.at(a)++;
    }

    for (int i = 1; i <= n; i++) {
        cout << m - ans.at(i) << endl;
    }
}

/* ===== 改善点 =====
   1. ans の中身は答え（正解数）ではなく「不正解だった回数」なので wrong などにすると、
      17 行目が「全問題数 − 不正解の数 ＝ 正解数」とそのまま読める

   vector<int> wrong(n + 1);          // 8 行目（13 行目も同じ名前にそろえる）
   cout << m - wrong.at(i) << endl;   // 17 行目
*/
