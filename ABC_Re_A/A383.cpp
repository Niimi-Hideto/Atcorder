#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> time(n);
    vector<int> water(n);

    for (int i = 0; i < n; i++) {
        cin >> time.at(i) >> water.at(i);
    }

    int ans = water.at(0);
    int tmp = time.at(0);
    int now = 0;

    for (int i = 1; i < n; i++) {
        now = time.at(i);
        ans = max(0, ans - (now - tmp));
        ans += water.at(i);
        tmp = now;
    }

    cout << ans << endl;
}
