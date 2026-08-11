#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    long long ans = 0;
    long long run = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s.at(i) == s.at(i - 1)) {
            run = 0;
        }
        run++;
        ans = (ans + run) % 998244353;
    }

    cout << ans << endl;
}
