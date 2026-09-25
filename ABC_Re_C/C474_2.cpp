#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p.at(i);
    }

    vector<int> last(n + 1);
    vector<int> a(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> a.at(i);
    }
    for (int i = 1; i <= q; i++) {
        last.at(a.at(i)) = i;
    }

    for (int i = 1; i <= n; i++) {
        if (last.at(p.at(i)) == 0) {
            cout << p.at(i) << " ";
        }
    }
    for (int i = 1; i <= q; i++) {
        if (last.at(a.at(i)) == i) {
            cout << a.at(i) << " ";
        }
    }
    cout << endl;
}

/* ===== 改善点 =====
   a を読むループと last を記録するループを分けなくていい。
   読んだ直後に last を更新すれば、後の操作で上書きされて最後の時刻が残る

   for (int i = 1; i <= q; i++) {
       cin >> a.at(i);
       last.at(a.at(i)) = i;
   }
*/
