#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> s;
    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            s.insert(x);
        }
        else {
            if (s.empty()) {
                cout << -1 << endl;
                continue;
            }

            auto itr = s.lower_bound(x);
            if (itr == s.end()) {
                itr--;
                cout << abs(x - *itr) << endl;
            }
            else if (itr == s.begin()) {
                cout << abs(x - *itr) << endl;
            }
            else {
                int tmp = *itr;
                itr--;
                int tmpp = *itr;

                if (abs(x - tmp) < abs(x - tmpp)) {
                    itr++;
                }

                cout << abs(x - *itr) << endl;
            }
        }
    }
}

/* ===== 改善点 =====
   1. 欲しいのは距離だけなので、近いほうを選ぶために itr を戻したり進めたりしなくていい。
      両側の値を取り出したら、2 つの距離の min を出力すれば済む（31–39 行目）
      tmp・tmpp も、x 以上の側（右）と x より小さい側（左）が名前で分かるようにする

                int right = *itr;                      // 31–39 行目
                itr--;
                int left = *itr;

                cout << min(abs(x - right), abs(x - left)) << endl;
*/
