#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() == 5 || s.size() == 10) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

/*
// 改善版（% を使う）
int main() {
    string s;
    cin >> s;

    if (s.size() % 5 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
// キモ：5の倍数かどうかは % 5 == 0 で判定。列挙より汎用的。
*/
