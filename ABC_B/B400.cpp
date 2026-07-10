#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long limit = 1;
    for (int i = 0; i < 9; i++) {
        limit *= 10;
    }

    long long ans = 1;
    long long tmp = n;
    for (int i = 1; i <= m; i++) {
        ans += tmp;
        tmp *= n;

        if (limit < ans) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}

// 【改善版】limit は直書き + チェックを tmp *= n の前に移す
// long long limit = 1000000000LL;
// long long ans = 1, tmp = n;
// for (int i = 1; i <= m; i++) {
//     ans += tmp;
//     if (limit < ans) { cout << "inf" << endl; return 0; }
//     tmp *= n;
// }
// cout << ans << endl;
