#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;

        if (s == "keep") {
            ans += (b - a);
        }
    }

    cout << ans << endl;
}
