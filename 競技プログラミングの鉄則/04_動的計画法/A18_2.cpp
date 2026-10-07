#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));
    dp.at(0).at(0) = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            if (j >= a.at(i) && dp.at(i - 1).at(j - a.at(i))) {
                dp.at(i).at(j) = true;
            }
        }
    }
    cout << (dp.at(n).at(s) ? "Yes" : "No") << endl;
}
