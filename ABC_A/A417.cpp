#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    string s;

    string ans;

    cin >> n >> a >> b >> s;

    for (int i = a; i < n - b; i++) {
        ans += s.at(i);
    }
    cout << ans << endl;
}

// 別解：substr(開始位置, 文字数) で1行
// cout << s.substr(a, n - a - b) << endl;