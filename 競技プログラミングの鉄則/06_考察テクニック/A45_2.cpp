#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    int w = 0, b = 0, r = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s.at(i) == 'W') {
            w++;
        }
        else if (s.at(i) == 'B') {
            b++;
        }
        else {
            r++;
        }
    }

    int card;
    if (c == 'W') {
        card = 0;
    }
    else if (c == 'B') {
        card = 1;
    }
    else {
        card = 2;
    }

    cout << ((b * 1 + r * 2) % 3 == card ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. 白は 0 なので合計に足しても変わらず、w は 34 行目で使っていない。数えなくていい（10・12–14 行目）

      白の分岐を消すと、最後の else に白も入ってしまうので、赤は else if で名指しする（18 行目）

    int b = 0, r = 0;                                  // 10 行目
        if (s.at(i) == 'B') {                          // 12–17 行目
            b++;
        }
        else if (s.at(i) == 'R') {                     // 18 行目
            r++;
        }
*/
