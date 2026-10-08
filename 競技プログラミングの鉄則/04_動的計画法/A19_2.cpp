#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cap;
    cin >> n >> cap;

    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w.at(i);
        cin >> v.at(i);
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(cap + 1, -1));
    dp.at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);

            if (j >= w.at(i) && dp.at(i - 1).at(j - w.at(i)) != -1) {
                dp.at(i).at(j) = max(dp.at(i - 1).at(j - w.at(i)) + v.at(i), dp.at(i).at(j));
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j <= cap; j++) {
        ans = max(ans, dp.at(n).at(j));
    }
    cout << ans << endl;
}
