#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    int ans = n;
    bool flag = true;
    int i = 0;
    while (flag && ans > 0) {
        if (vec.at(i++) == 0) {
            ans--;
        }
        else {
            flag = false;
        }
    }
    flag = true;
    i = (int)vec.size() - 1;
    while (flag && ans > 0) {
        if (vec.at(i--) == 0) {
            ans--;
        }
        else {
            ans--;
            flag = false;
        }
    }
    cout << ans << endl;

}

// 【改善版】右パスの両ブランチで ans-- が共通なのでまとめる
// while (flag && ans > 0) {
//     ans--;
//     if (vec.at(i--) != 0) flag = false;
// }