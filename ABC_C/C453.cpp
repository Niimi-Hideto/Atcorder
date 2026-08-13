#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long position = 1;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            bool before = (position > 0);

            if ((mask >> i) & 1) {
                position += 2 * l.at(i);
            }
            else {
                position -= 2 * l.at(i);
            }

            bool after = (position > 0);
            if (before != after) {
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
