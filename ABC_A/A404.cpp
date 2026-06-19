#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (char c = 'a'; c <= 'z'; c++) {
        if (count(s.begin(), s.end(), c) == 0) {
            cout << c << endl;
            break;
        }
    }
}
