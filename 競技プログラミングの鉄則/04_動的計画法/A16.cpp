#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a.at(i);
    }
    for (int i = 3; i <= n; i++) {
        cin >> b.at(i);
    }

    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++) {
        if (i == 2) {
            dp.at(i) = a.at(i);
            continue;
        }

        dp.at(i) = min(dp.at(i - 1) + a.at(i), dp.at(i - 2) + b.at(i));
    }
    cout << dp.back() << endl;
}
