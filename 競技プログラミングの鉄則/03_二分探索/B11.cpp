#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        int it = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << it << endl;
    }
}

/* ===== 改善点 =====
   - a.begin() を引いた時点で中身はイテレータではなく整数（X より小さい要素の個数）なので、
     it ではなく中身に合った名前にする

   int cnt = lower_bound(a.begin(), a.end(), x) - a.begin();
   cout << cnt << endl;
*/
