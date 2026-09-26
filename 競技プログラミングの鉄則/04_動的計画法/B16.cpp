#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h.at(i);
    }

    vector<int> dp(n + 1, 0);
    dp.at(2) = abs(h.at(2) - h.at(1));
    for (int i = 3; i <= n; i++) {
        dp.at(i) = min(dp.at(i - 2) + abs(h.at(i) - h.at(i - 2)), dp.at(i - 1) + abs(h.at(i) - h.at(i - 1)));
    }
    cout << dp.at(n) << endl;
}
