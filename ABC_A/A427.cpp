#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans;

    for (int i = 0; i < (int)s.size(); i++) {
        if (((int)s.size() + 1) / 2 == i + 1) {
            continue;
        }
        else {
            ans += s.at(i);
        }
    }
    cout << ans << endl;
}

// 別解：erase を使うとループ不要
// s.erase(s.size() / 2, 1);  // 中央インデックスから1文字削除
// cout << s << endl;
