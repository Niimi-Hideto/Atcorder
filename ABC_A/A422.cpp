#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0;

    string ans;

    if (s.at(2) != '8') {
        i = s.at(2) - '0';
        s.at(2) = (i + 1) + '0';
    }
    else {
        i = s.at(0) - '0';
        s.at(0) = (i + 1) + '0';
        s.at(2) = '1';
    }
    cout << s << endl;
}
