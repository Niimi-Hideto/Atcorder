#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    bool ok = true;
    if (a.at(0) == 'A' && b.at(1) == 'D') {
        ok = false;
    }
    else if (a.at(1) == 'A' && b.at(0) == 'D') {
        ok = false;
    }
    else if (b.at(0) == 'A' && a.at(1) == 'D') {
        ok = false;
    }
    else if (b.at(1) == 'A' && a.at(0) == 'D') {
        ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. 対角線の4通りを手で並べると、1つ書き漏らしても気づきにくい。A と D の位置を探して
      「縦と横のずれの合計がちょうど1」（＝辺を共有）で判定すれば漏れようがなく、大きいグリッドでも同じ式で使える

   vector<string> g = {a, b};
   int ai, aj, di, dj;
   for (int i = 0; i < 2; i++) {
       for (int j = 0; j < 2; j++) {
           if (g.at(i).at(j) == 'A') { ai = i; aj = j; }
           if (g.at(i).at(j) == 'D') { di = i; dj = j; }
       }
   }
   bool ok = (abs(ai - di) + abs(aj - dj) == 1);
*/
