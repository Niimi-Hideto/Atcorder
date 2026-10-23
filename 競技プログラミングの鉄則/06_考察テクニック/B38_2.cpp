#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    s = "X" + s;

    vector<int> a(n + 1, 1);
    vector<int> b(n + 1, 1);
    for (int i = 1; i <= n - 1; i++) {
        if (s.at(i) == 'A') {
            a.at(i + 1) = a.at(i) + 1;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (s.at(i) == 'B') {
            b.at(i) = b.at(i + 1) + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += max(a.at(i), b.at(i));
    }

    cout << ans << endl;
}
