#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    long long tmp;
    long long a1 = x;
    long long a2 = y;
    for (int i = 0; i < 8; i++) {
        tmp = a1 + a2;
        if (tmp >= 10) {
            bool flag = true;
            while (flag) {
                if (tmp % 10 == 0) {
                    tmp /= 10;
                }
                else {
                    flag = false;
                }
            }
            string a = to_string(tmp);
            reverse(a.begin(), a.end());
            tmp = stoll(a);
        }
        a1 = a2;
        a2 = tmp;
    }
    cout << a2 << endl;
}

// 【改善版】while ループと if (tmp >= 10) は不要。stoll が先頭ゼロを無視するので直接変換できる。
// for (int i = 0; i < 8; i++) {
//     tmp = a1 + a2;
//     string s = to_string(tmp);
//     reverse(s.begin(), s.end());
//     tmp = stoll(s);
//     a1 = a2;
//     a2 = tmp;
// }
