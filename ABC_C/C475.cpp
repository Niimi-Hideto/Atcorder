#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    long long l;
    cin >> n >> s >> l;

    vector<long long> pre(n + 1);
    for (int i = 2; i <= n; i++) {
        long long tmp;
        cin >> tmp;
        pre.at(i) = pre.at(i - 1) + tmp;
    }

    int ans = 1;
    for (int left = 1; left <= s; left++) {
        for (int right = s; right <= n; right++) {
            long long movel = pre.at(s) - pre.at(left);
            long long mover = pre.at(right) - pre.at(s);

            long long cost = min(movel * 2 + mover, movel + mover * 2);

            if (cost <= l) {
                ans = max(ans, right - left + 1);
            }
        }
    }
    cout << ans << endl;
}
