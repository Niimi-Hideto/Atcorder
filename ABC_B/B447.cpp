#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int tmp = 0;
    int now = 0;

    for (int i = 0; i < s.size(); i++) {
        now = count(s.begin(), s.end(), s.at(i));
        tmp = max(now, tmp);
    }

    for (int i = 0; i < s.size(); i++) {
        if (count(s.begin(), s.end(), s.at(i)) == tmp) {
            continue;
        }
        else {
            cout << s.at(i);
        }
    }
    cout << endl;
}
