#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;

    vector<int> d(t + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        d.at(l)++;
        d.at(r)--;
    }

    int ans = 0;
    for (int i = 0; i < t; i++) {
        ans += d.at(i);
        cout << ans << endl;
    }
}
