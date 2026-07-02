#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    char ans;

    for (int i = 0; i < (int)s.size(); i++) {
        ans = s.at(i);
        if (count(s.begin(), s.end(), ans) == 1) {
            cout << ans << endl;
            break;
        }
    }
}

// 【改善版】範囲for文で ans 変数と (int)s.size() キャストが不要になる
// for (char c : s) {
//     if (count(s.begin(), s.end(), c) == 1) {
//         cout << c << endl;
//         break;
//     }
// }
