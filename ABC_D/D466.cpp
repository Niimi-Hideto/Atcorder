
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> r(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> r.at(i) >> c.at(i);
    }

    set<int> ans_r;
    set<int> ans_c;
    bool flag = true;
    int ans = 0;

    for (int i = m - 1; i >= 0; i--) {
        flag = true;
        if (ans_r.count(r.at(i)) == 0) {
            ans_r.insert(r.at(i));
        }
        else {
            flag = false;
        }
        if (ans_c.count(c.at(i)) == 0) {
            ans_c.insert(c.at(i));
        }
        else {
            flag = false;
        }

        if (flag) {
            ans++;
        }
    }
    cout << ans << endl;
}