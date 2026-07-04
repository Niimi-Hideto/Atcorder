#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool flag = false;
    int tmp;
    for (int i = 0; i < s.size(); i++) {
        if (flag && s.at(i) == '#') {
            cout << tmp + 1 << ',' << i + 1 << endl;
            flag = false;
        }
        else if (s.at(i) == '#') {
            flag = true;
            tmp = i;
        }
    }
}
