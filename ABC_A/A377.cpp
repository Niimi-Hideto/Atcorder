#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool flag = false;

    if (count(s.begin(), s.end(), 'A') != 0 &&
        count(s.begin(), s.end(), 'B') != 0 &&
        count(s.begin(), s.end(), 'C') != 0) {
        flag = true;
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
