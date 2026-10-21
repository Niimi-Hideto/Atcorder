#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        while (!st.empty() && st.top().second <= a) {
            st.pop();
        }

        if (i >= 2) {
            cout << " ";
        }
        if (st.empty()) {
            cout << -1;
        }
        else {
            cout << st.top().first;
        }

        st.push(make_pair(i, a));
    }
    cout << endl;
}

/* ===== 最初に書いた形（set と map） =====
   値の小さい順に並ぶ set で「a より大きい最小の値」を探していたが、
   欲しいのは「a より大きい日のうち一番新しい日」なので違う答えになる。
   22 行目は a より大きい側を消していたが、もう起算日にならないのは a より小さい側

    set<int> s;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        s.insert(a);
        m[a] = i;
        auto itr = s.upper_bound(a);
        if (itr == s.end()) {
            cout << -1 << endl;
            continue;
        }
        cout << m[*itr] << endl;
        s.erase(itr, s.end());
    }
*/
