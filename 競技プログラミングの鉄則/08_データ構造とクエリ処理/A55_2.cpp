#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> s;
    for (int i = 1; i <= q; i++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            s.insert(x);
        }
        else if (type == 2) {
            s.erase(x);
        }
        else {
            auto it = lower_bound(s.begin(), s.end(), x);
            if (it == s.end()) {
                cout << -1 << endl;
            }
            else {
                cout << *it << endl;
            }
        }
    }
}

/* ===== 改善点 =====
   1. set に外から lower_bound(s.begin(), s.end(), x) を使うと、set は i 番目へ一気に飛べないので
      1 つずつ進むことになり 1 回 O(N)。最悪 Q × N ≈ 10^10 回で、今回はテストが軽くて通っただけ（ABC451 C の TLE と同じ）。
      set ではメンバ関数の s.lower_bound(x) を使う（O(log N)）（20 行目）

            auto it = s.lower_bound(x);                // 20 行目
*/
