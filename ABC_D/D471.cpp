#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, v;
    cin >> q >> v;

    multiset<int> s;
    for (int i = 0; i < q; i++) {
        int num, t;
        cin >> num >> t;

        if (num == 1) {
            int w;
            cin >> w;

            w = w - t;
            s.insert(w);
        }
        else {
            if (s.size() == 0) {
                cout << -1 << endl;
            }
            else {
                int tmp = *rbegin(s);
                auto idx = prev(s.end());
                s.erase(idx);
                tmp += t;

                if (tmp > v) {
                    cout << v << endl;
                }
                else {
                    cout << tmp << endl;
                }
            }

        }
    }
}

// 改善点: rbegin(s)とprev(s.end())で同じ場所を2通りに取得してるので1つにまとめる
// イテレータなのにidxという名前も紛らわしいのでitに変更
// if (s.empty()) {
//     cout << -1 << endl;
// }
// else {
//     auto it = prev(s.end());
//     int tmp = *it;
//     s.erase(it);
//     tmp += t;
//
//     if (tmp > v) {
//         cout << v << endl;
//     }
//     else {
//         cout << tmp << endl;
//     }
// }
