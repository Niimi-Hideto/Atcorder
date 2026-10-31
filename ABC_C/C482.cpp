#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n, q;
    cin >> h >> w >> n >> q;

    vector<int> ud;
    vector<int> lr;
    for (int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;

        ud.push_back(r);
        lr.push_back(c);
    }
    sort(ud.begin(), ud.end());
    sort(lr.begin(), lr.end());

    for (int i = 0; i < q; i++) {
        int type, u, d;
        cin >> type >> u >> d;

        if (type == 1) {
            auto r = upper_bound(ud.begin(), ud.end(), d);
            auto l = lower_bound(ud.begin(), ud.end(), u);
            if (l == ud.end()) {
                cout << 0 << endl;
                continue;
            }

            else if (r == ud.end()) {
                cout << r - l << endl;
                continue;
            }

            cout << r - l << endl;
        }
        else {
            auto r = upper_bound(lr.begin(), lr.end(), d);
            auto l = lower_bound(lr.begin(), lr.end(), u);

            if (l == lr.end()) {
                cout << 0 << endl;
                continue;
            }
            else if (r == lr.end()) {
                cout << r - l << endl;
                continue;
            }

            cout << r - l << endl;
        }
    }
}

/* ===== 改善点 =====
   1. 27–35・43–50 行目の if はいらない。l == end のときは r も end なので r - l = 0、
      r == end のときも出しているのは r - l。3 通りとも答えは r - l なので、
      if を消して 37・52 行目の cout だけ残す（27–36・43–51 行目を消す）
*/
