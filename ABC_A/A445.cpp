#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    char f, l;

    f = s.at(0);
    l = s.at((int)s.size() - 1);

    if (f == l) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

// 別解：front()/back() を使うと変数不要
// if (s.front() == s.back()) { ... }
