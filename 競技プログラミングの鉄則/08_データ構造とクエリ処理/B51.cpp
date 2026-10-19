#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> l, r;
    for (int i = 1; i <= (int)s.size(); i++) {
        if (s.at(i - 1) == '(') {
            l.push(i);
        }
        else {
            r.push(i);
        }

        if (!l.empty() && !r.empty()) {
            cout << l.top() << " " << r.top() << endl;
            l.pop();
            r.pop();
        }
    }
}

/* ===== 改善点 =====
   1. S は対応が取れているので、')' が来たとき l は必ず空でなく、r に積んだ ')' はすぐ組になって消える。
      r には 1 個より多くたまらず、中身はいつも今の i なので、r はいらない（8・13–21 行目）

    stack<int> l;                                      // 8 行目
        else {                                         // 13 行目〜
            cout << l.top() << " " << i << endl;
            l.pop();
        }
                                                       // 17–21 行目の if は消す
*/
