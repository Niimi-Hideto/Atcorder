#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 1;
    for (int i = 1; i < n; i++) {
        int tmp = ans;
        for (int j = 0; j < 4; j++) {
            ans += tmp % 10;
            tmp = tmp / 10;
        }
    }
    cout << ans << endl;
}

// 【改善版】桁数が増えても壊れない while 版
// for (int i = 1; i < n; i++) {
//     int tmp = ans;
//     while (tmp > 0) {
//         ans += tmp % 10;
//         tmp /= 10;
//     }
// }
