#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    vector<pair<int, int>> ans;

    while (X > 1 || Y > 1) {
        ans.push_back(make_pair(X, Y));

        if (X >= Y) {
            X -= Y;
        }
        else {
            Y -= X;
        }
    }

    bool ok = false;
    if (!ans.empty()) {
        if (ans.back().first == 1 && ans.back().second == 2
            || ans.back().first == 2 && ans.back().second == 1) {
            ok = true;
        }
    }

    cout << ans.size() << endl;
    if (ok) {
        reverse(ans.begin(), ans.end());
        for (pair<int, int> x : ans) {
            cout << x.first << " " << x.second << endl;
        }
    }
}

/* ===== 改善点 =====
   1. X と Y の最大公約数が 1 なので、逆にたどると必ず (1, 1) に着く（ユークリッドの互除法と同じ動き）。
      最後に記録されるのはいつも (1, 2) か (2, 1) なので、21〜27 行目の ok と 30 行目の if は要らない
   2. pair<int, int> x だと x.first が「x の値」になり、問題文の x と混ざる。p などにする。push_back は {X, Y} と書ける

   ans.push_back({X, Y});                         // 11 行目
   cout << ans.size() << endl;                    // 21〜35 行目
   reverse(ans.begin(), ans.end());
   for (pair<int, int> p : ans) {
       cout << p.first << " " << p.second << endl;
   }
*/
