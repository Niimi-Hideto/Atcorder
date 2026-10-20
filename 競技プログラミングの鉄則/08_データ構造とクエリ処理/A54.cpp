#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> table;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            string name;
            int score;
            cin >> name >> score;

            if (table.count(name) == 0) {
                table[name] = score;
            }
            else {
                if (table.at(name) < score) {
                    table.at(name) = score;
                }
            }
        }
        else if (type == 2) {
            string name;
            cin >> name;

            cout << table.at(name) << endl;
        }
    }
}

/* ===== 改善点 =====
   1. 問題文は「成績が y 点になった」なので、今より低い点が来ても上書きする。
      table[name] = score; は、まだ登録されていない名前でも登録済みの名前でも同じ 1 行で動くので、if の場合分けはいらない（18–25 行目）

            table[name] = score;                       // 18–25 行目
*/
