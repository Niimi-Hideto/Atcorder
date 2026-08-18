#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 1;
    int cnt = 1;
    char prev_char = s.at(0);

    for (int i = 1; i < (int)s.size(); i++) {
        char tmp = s.at(i);
        if (tmp != prev_char) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        prev_char = tmp;

        ans = (ans + cnt) % 998244353;
    }
    cout << ans << endl;
}
