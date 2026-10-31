#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'o') {
            cnt++;
        }
    }
    cout << (cnt % 2 == 0 ? "even" : "odd") << endl;
}
