#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    bool flag = true;
    for (int i = 1; i < s.size(); i++) {
        if (isupper(s.at(i))) {
            if (count(t.begin(), t.end(), s.at(i - 1)) == 0) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
