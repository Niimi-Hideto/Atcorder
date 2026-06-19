#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        if (isupper(s.at(i))) {
            ans += s.at(i);
        }
    }
    cout << ans << endl;
}
