#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (t.at(i) == '*' || t.at(i) == s.at(i)) {
            continue;
        }
        else {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
