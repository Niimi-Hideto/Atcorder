#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    string s;
    string ans;
    bool flag = true;

    cin >> n >> l >> r >> s;

    ans = s.substr(l - 1, r - l + 1);

    for (int i = 0; i < ans.size(); i++) {
        if (ans.at(i) != 'o') {
            flag = false;
            cout << "No" << endl;
            break;
        }
    }
    if (flag == true) {
        cout << "Yes" << endl;
    }
}

// 別解①：substr不要、直接sをループ
// for (int i = l - 1; i < r; i++) {
//     if (s.at(i) != 'o') { flag = false; break; }
// }
