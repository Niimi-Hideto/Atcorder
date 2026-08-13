//解けなかった．

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab.at(i).first >> ab.at(i).second;
    }

    int m;
    cin >> m;

    vector<string> s(m);
    vector<vector<vector<bool>>> exists(11, vector<vector<bool>>(11, vector<bool>(26, false)));

    for (int i = 0; i < m; i++) {
        cin >> s.at(i);
        int len = (int)s.at(i).size();
        for (int p = 0; p < len; p++) {
            int c = s.at(i).at(p) - 'a';
            exists.at(len).at(p + 1).at(c) = true;
        }
    }

    for (int i = 0; i < m; i++) {
        bool flag = true;
        if ((int)s.at(i).size() != n) {
            flag = false;
        }
        else {
            for (int j = 0; j < n; j++) {
                int len = ab.at(j).first;
                int pos = ab.at(j).second;
                int c = s.at(i).at(j) - 'a';
                if (!exists.at(len).at(pos).at(c)) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}
