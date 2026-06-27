#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string w;
        cin >> w;
        bool Takahashi = true;
        bool Aoki = true;

        for (int j = 0; j < w.size(); j++) {
            if (count(s.begin(), s.end(), w.at(j)) == 0) {
                Takahashi = false;
            }
            if (count(t.begin(), t.end(), w.at(j)) == 0) {
                Aoki = false;
            }
        }
        if (Takahashi && Aoki == false) {
            cout << "Takahashi" << endl;
        }
        else if (Takahashi == false && Aoki) {
            cout << "Aoki" << endl;
        }
        else {
            cout << "Unknown" << endl;
        }
    }
}

// == false より !Aoki / !Takahashi と書く方がスッキリ（!はbool反転）
// n, m は読んでるが未使用。s.size()/t.size() で代替しているので問題ないが消せない
