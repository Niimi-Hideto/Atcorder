#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        a.at(i) = a.at(i - 1) + tmp;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << a.at(r) - a.at(l - 1) << endl;
    }
}

/* ===== 改善点 =====
   a の中身は累積和なので、名前を pre（prefix sum の略）にする

   vector<int> pre(n + 1);   // pre.at(i) = 1日目〜i日目の合計、pre.at(0) = 0
   pre.at(i) = pre.at(i - 1) + tmp;
   cout << pre.at(r) - pre.at(l - 1) << endl;
*/
