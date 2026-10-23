#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool ok = false;
    for (int i = 0; i < (int)s.size() - 2; i++) {
        if (s.at(i) == s.at(i + 1) && s.at(i + 1) == s.at(i + 2)) {
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
