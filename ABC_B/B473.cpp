#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (a.count(tmp) == 0) {
            a.insert(tmp);
        }
        else {
            a.erase(tmp);
        }
    }

    int ans = 0;
    int size = a.size();
    for (int i = 0; i < size; i++) {
        int tmp = *rbegin(a);
        a.erase(tmp);

        ans += tmp;
    }
    cout << ans << endl;
}

// 改善案：21〜28行目はrbegin()+eraseで取り出さなくても、
// setは範囲for文でそのまま舐められる（順番は合計に関係ないので十分）
//
// int ans = 0;
// for (int x : a) {
//     ans += x;
// }
