#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<bool> all(n + 1);
    vector<set<int>> ok(n + 1);
    for (int query = 0; query < q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;

            ok.at(x).insert(y);
        }
        else if (type == 2) {
            int x;
            cin >> x;

            all.at(x) = true;
        }
        else {
            int x, y;
            cin >> x >> y;

            if (all.at(x)) {
                cout << "Yes" << endl;
            }
            else {
                cout << (ok.at(x).count(y) != 0 ? "Yes" : "No") << endl;
            }
        }
    }
}

/* 改善点（変わる行だけ）

// 30〜35行目：Yes の条件は「all が true、または set に y がある」の 1 つ（|| は左が true なら右を見ない）
            cout << (all.at(x) || ok.at(x).count(y) ? "Yes" : "No") << endl;
*/
