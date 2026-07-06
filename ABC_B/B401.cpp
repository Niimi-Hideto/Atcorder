#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;



    bool log = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "login") {
            log = true;
        }
        else if (s == "logout") {
            log = false;
        }
        else if (!log && s == "private") {
            ans++;
        }
    }
    cout << ans << endl;
}
