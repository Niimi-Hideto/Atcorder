#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(5);
    for (int i = 0; i < 5; i++) {
        cin >> s.at(i);
    }

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        int tmp = 0;
        for (int j = 0; j < 5; j++) {
            if (s.at(i).at(j) == 'o') {
                tmp++;
            }
        }
        cnt = max(cnt, tmp);
    }

    for (int j = 0; j < 5; j++) {
        int tmp = 0;
        for (int i = 0; i < 5; i++) {
            if (s.at(i).at(j) == 'o') {
                tmp++;
            }
        }
        cnt = max(cnt, tmp);
    }

    int tmp = 0;
    for (int i = 0; i < 5; i++) {
        if (s.at(i).at(i) == 'o') {
            tmp++;
        }
        cnt = max(cnt, tmp);
    }

    tmp = 0;
    for (int i = 0; i < 5; i++) {
        if (s.at(i).at(4 - i) == 'o') {
            tmp++;
        }
        cnt = max(cnt, tmp);
    }

    cout << 5 - cnt << endl;
}

/* ===== 改善点 =====
   1. 斜めの max がループの中にあり、1マスごとに比べている。縦・横（18・28 行目）と同じく、
      5マス数え終わってから1回だけ比べる（36・44 行目を、それぞれ 1 行下の } の外へ）

        }
        cnt = max(cnt, tmp);                           // 36 行目 → 37 行目の } の後ろ

        }
        cnt = max(cnt, tmp);                           // 44 行目 → 45 行目の } の後ろ
*/
