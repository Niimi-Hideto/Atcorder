#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s.at(i);
    }

    vector<int> ans(n + 1);
    for (int test = 1; test <= m; test++) {
        string t;
        cin >> t;

        vector<vector<int>> tmp(2);
        for (int i = 1; i <= n; i++) {
            if (s.at(i).size() != t.size()) continue;

            int cnt = 0;
            for (int j = 0; j < (int)t.size(); j++) {
                if (s.at(i).at(j) != t.at(j)) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                tmp.at(0).push_back(i);
            }
            else if (cnt == 1) {
                tmp.at(1).push_back(i);
            }
        }

        if (tmp.at(0).size() == 1) {
            ans.at(tmp.at(0).at(0))++;
        }
        else if (tmp.at(0).size() == 0 && tmp.at(1).size() == 1) {
            ans.at(tmp.at(1).at(0))++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans.at(i) << endl;
    }
}

/* ===== 改善点 =====
   1. tmp.at(0) が「完全一致」、tmp.at(1) が「1文字違い」という意味が名前から分からない。
      添字の 0 / 1 に意味を持たせず、名前の付いた2つの vector にする
   2. 名前は互いに異なるので完全一致は0人か1人。1人なら36行目の if に入るので、
      else if に来た時点で必ず0人。39行目の tmp.at(0).size() == 0 && は要らない

   vector<int> exact, one_diff;   // 完全一致の候補者、1文字違いの候補者
   if (cnt == 0) exact.push_back(i);
   else if (cnt == 1) one_diff.push_back(i);

   if (exact.size() == 1) {
       ans.at(exact.at(0))++;
   }
   else if (one_diff.size() == 1) {
       ans.at(one_diff.at(0))++;
   }
*/
