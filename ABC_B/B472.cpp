#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i);
    }

    int ans = 10000000;
    for (int i = 1; i < n; i++) {
        int left = l.at(0);
        int right = l.at(n - 1);
        int tmp = 0;
        for (int j = 1; j < i; j++) {
            left += l.at(j);
        }
        for (int k = i; k < n - 1; k++) {
            right += l.at(k);
        }

        if (left > right) {
            tmp = left - right;
        }
        else {
            tmp = right - left;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

// 改善点: left/rightを毎回計算し直さず、累積和的に1ピースずつ足して持ち回す
// int total = 0;
// for (int x : l) total += x;
//
// int ans2 = INT_MAX;
// int left = 0;
// for (int i = 0; i < n - 1; i++) {
//     left += l.at(i);
//     int right = total - left;
//     ans2 = min(ans2, abs(left - right));
// }
// cout << ans2 << endl;
