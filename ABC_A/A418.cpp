#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    string ans;

    cin >> n >> s;

    if (n >= 3) {
        ans = s.substr(n - 3);
    }

    if (ans == "tea") {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

// 別解：s.size() を使えば n の入力不要
// if (s.size() >= 3 && s.substr(s.size() - 3) == "tea") cout << "Yes";
// else cout << "No";
