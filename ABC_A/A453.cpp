#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool flag = true;

    string result;

    for (int i = 0; i < n; i++) {
        if (flag == true) {
            if (s.at(i) != 'o') {
                result += s.at(i);
                flag = false;
            }
        }
        else {
            result += s.at(i);
        }
    }
    cout << result << endl;
}

/*
// while版（別解）
int main() {
    int n;
    string s;
    cin >> n >> s;

    int i = 0;

    while (i < n && s.at(i) == 'o') {
        i++;
    }

    cout << s.substr(i) << endl;
}
// キモ：i < n を先に書いて範囲外アクセスを防ぐ
// substr(i) でi文字目以降を取り出す（全部oなら空文字列）
*/
