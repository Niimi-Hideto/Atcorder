#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> l(n + 1);
    int left_zero = n + 1, right_zero = -1;
    for (int i = 1; i <= n; i++) {
        cin >> l.at(i);
        if (l.at(i) == 0) {
            left_zero = min(left_zero, i);
            right_zero = max(right_zero, i);
        }
    }

    int ans = 0;
    for (int i = r; i >= left_zero; i--) {
        if (l.at(i) == 0) {
            ans += 1;
        }
        else {
            ans += 2;
        }
    }
    for (int i = r + 1; i <= right_zero; i++) {
        if (l.at(i) == 0) {
            ans += 1;
        }
        else {
            ans += 2;
        }
    }

    cout << ans << endl;
}
