#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans;

    if (n == 1) {
        ans += '=';
    }
    else if ((n % 2) == 0) {
        for (int i = 0; i < n; i++) {
            if ((n / 2) == i + 1 || (n / 2) + 1 == i + 1) {
                ans += '=';
            }
            else {
                ans += '-';
            }
        }
    }
    else if ((n % 2) == 1) {
        for (int i = 0; i < n; i++) {
            if ((n / 2) + 1 == i + 1) {
                ans += '=';
            }
            else {
                ans += '-';
            }
        }
    }
    cout << ans << endl;
}

// 別解：string(k, '-') で繰り返し文字列を生成
// if (n % 2 == 1) {
//     cout << string(n/2, '-') << "=" << string(n/2, '-') << endl;
// }
// else {
//     cout << string(n/2-1, '-') << "==" << string(n/2-1, '-') << endl;
// }
