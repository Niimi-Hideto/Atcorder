#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    string s2 = "x" + s + "x";

    int ans = 0;

    for (int i = 1; i < n + 1; i++) {
        if (s2.at(i) == 'x') {
            if (s2.at(i - 1) == 'x' && s2.at(i + 1) == 'x') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
