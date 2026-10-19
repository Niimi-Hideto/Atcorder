#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    string a;
    cin >> n >> x >> a;

    queue<int> q;
    q.push(x);
    a.at(x - 1) = '@';

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        if (pos > 1 && a.at(pos - 2) == '.') {
            q.push(pos - 1);
            a.at(pos - 2) = '@';
        }
        if (pos < n && a.at(pos) == '.') {
            q.push(pos + 1);
            a.at(pos) = '@';
        }
    }
    cout << a << endl;
}

/* ===== 改善点 =====
   1. ボールの番号（1 始まり）と文字列の添字（0 始まり）が混ざっていて、毎回ずらして書く必要がある（WA の原因）。
      読んだ直後に x-- して全部 0 始まりにそろえると、ボール pos-1・pos+1 がそのまま a.at(pos - 1)・a.at(pos + 1) になる（7–23 行目）

    cin >> n >> x >> a;
    x--;                                               // 0 始まりにそろえる

    a.at(x) = '@';                                     // 11 行目

        if (pos > 0 && a.at(pos - 1) == '.') {         // 17 行目
            a.at(pos - 1) = '@';                       // 19 行目
        if (pos < n - 1 && a.at(pos + 1) == '.') {     // 21 行目
            a.at(pos + 1) = '@';                       // 23 行目
*/
