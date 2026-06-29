#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool flag = true;

    if (n % 2 == 0) {
        flag = false;
    }
    for (int i = 0; i < n; i++) {
        if ((((int)s.size() + 1) / 2) - 1 >= i + 1) {
            if (s.at(i) != '1') {
                flag = false;
                break;
            }
        }
        else if ((((int)s.size() + 1) / 2) == i + 1) {
            if (s.at(i) != '/') {
                flag = false;
                break;
            }
        }
        else {
            if (s.at(i) != '2') {
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
