#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> m;
    int cnt = 1;
    for (int i = 1; i <= q; i++) {
        string s;
        cin >> s;

        if (m.count(s) == 0) {
            m[s] = cnt;
            cout << m.at(s) << endl;
            cnt++;
        }
        else {
            cout << m.at(s) << endl;
        }
    }
}

/* ===== 改善点 =====
   1. どちらの場合も同じ cout << m.at(s) を出しているので、if の中は「まだなければ登録する」だけにして、
      出力は if の後ろに 1 回だけ書く。同じ処理を 2 か所に書くと、片方だけ直し忘れる元になる（14–21 行目）

   2. 口座は消えないので、次の ID は「今まで登録した数 + 1」＝ m.size() + 1。cnt で別に数えなくていい（9・15・17 行目）。
      m[s] = m.size() + 1; と 1 行で書くと、m[s] で s が登録されるのが先か m.size() を読むのが先かが紛らわしいので、
      先に id に入れてから登録する

    (9 行目は消す)
        if (m.count(s) == 0) {                         // 14–21 行目
            int id = m.size() + 1;
            m[s] = id;
        }
        cout << m.at(s) << endl;
*/
