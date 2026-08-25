
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ab(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> ab.at(i).at(0) >> ab.at(i).at(1);
    }

    int m;
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s.at(i);
    }

    vector<vector<vector<bool>>> alphabet(11, vector<vector<bool>>(10, vector<bool>(26)));
    for (int i = 0; i < m; i++) {
        string tmp = s.at(i);

        for (int j = 0; j < (int)tmp.size(); j++) {
            alphabet.at((int)tmp.size()).at(j).at((tmp.at(j) - 'a')) = true;
        }
    }

    for (int i = 0; i < m; i++) {
        string tmp = s.at(i);
        bool ok = false;

        if ((int)tmp.size() == n) {
            ok = true;
            for (int j = 0; j < n; j++) {
                if (alphabet.at(ab.at(j).at(0)).at(ab.at(j).at(1) - 1).at((tmp.at(j) - 'a')) == false) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}

// 改善案：ab を vector<vector<int>> ではなく vector<pair<int,int>> にする
// （A_i, B_i という意味の違う2値の組なので、.at(0)/.at(1) より .first/.second の方が読みやすい）
//
// vector<pair<int,int>> ab(n);
// for (int i = 0; i < n; i++) {
//     cin >> ab.at(i).first >> ab.at(i).second;
// }
// ...
// alphabet.at(ab.at(j).first).at(ab.at(j).second - 1).at((tmp.at(j) - 'a'))