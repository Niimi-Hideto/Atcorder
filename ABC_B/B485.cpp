#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m && s.at(i).at(j) == 'x' && s.at(i).at(j + 1) == 'x') {
                cout << "Faucet" << " " << i + 1 << endl;
                return 0;
            }
            else if (s.at(i).at(j) == 'x') {
                cout << "Drain" << " " << j + 1 << endl;
                return 0;
            }
        }
    }
}

/* 改善点（変わる行だけ）

// ① 15行目の「隣も x」の判定は、「その行が全部 x か」で書く（蛇口が詰まっている ⇔ その行が全部 x）。
//    行ごとの判定なので j のループの外（13行目のすぐ内側）に出す。j + 1 < m もいらなくなる。
//    19行目の else if は、ただの if にして j のループの中に残す
        if (s.at(i) == string(m, 'x')) {
            cout << "Faucet " << i + 1 << endl;
            return 0;
        }
            if (s.at(i).at(j) == 'x') {

// ② 16・20行目：文字列は空白までつなげて書ける
                cout << "Faucet " << i + 1 << endl;
                cout << "Drain " << j + 1 << endl;
*/
