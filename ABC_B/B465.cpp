#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    int ans = 0;
    if (a < l && b < l) {
        ans += (b - a) * y;

    }
    else if (a <= l && l <= b && b <= r) {
        ans += (l - a) * y;
        ans += ((b - a) - (l - a)) * x;

    }
    else if (l <= a && b <= r) {
        ans += (b - a) * x;

    }
    else if (l <= a && a <= r && r <= b) {
        ans += (r - a) * x;
        ans += ((b - a) - (r - a)) * y;

    }
    else if (a <= l && r <= b) {
        ans += (l - a) * y;
        ans += (b - r) * y;
        ans += (r - l) * x;
    }
    else {
        ans += (b - a) * y;
    }

    cout << ans << endl;
}

// 【改善版】1時間ごとにループして割引区間内かチェックするだけ。場合分け不要
// for (int t = a; t < b; t++) {
//     if (l <= t && t < r) ans += x;
//     else ans += y;
// }
// cout << ans << endl;
