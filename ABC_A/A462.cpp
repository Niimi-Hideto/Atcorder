#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result;

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '0' || s.at(i) == '1' || s.at(i) == '2' || s.at(i) == '3' || s.at(i) == '4' ||
            s.at(i) == '5' || s.at(i) == '6' || s.at(i) == '7' || s.at(i) == '8' || s.at(i) == '9') {
            result += s.at(i);
        }
    }
    cout << result << endl;
}

// isdigit() を使うと数字判定をまとめて書ける
// if (isdigit(s.at(i))) で '0'〜'9' の10個を並べる必要がなくなる
/*
    for (int i = 0; i < (int)s.size(); i++) {
        if (isdigit(s.at(i))) {
            result += s.at(i);
        }
    }
*/