#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int i = 0;
    int j = 0;
    int ans = 0;

    while (i < (int)s.size() && j < (int)t.size()) {
        int sa = 0;
        int ta = 0;
        //Sの処理
        while (i < (int)s.size()) {
            if (s.at(i) == 'A') {
                sa++;
                i++;
            }
            else {
                break;
            }
        }
        //Tの処理
        while (j < (int)t.size()) {
            if (t.at(j) == 'A') {
                ta++;
                j++;
            }
            else {
                break;
            }
        }
        ans += abs(sa - ta);
        if (i < (int)s.size() && j < (int)t.size()) {
            if (s.at(i) == t.at(j)) {
                i++;
                j++;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (i < (int)s.size()) {
        while (i < (int)s.size()) {
            if (s.at(i) == 'A') {
                ans++;
                i++;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (j < (int)t.size()) {
        while (j < (int)t.size()) {
            if (t.at(j) == 'A') {
                ans++;
                j++;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}

