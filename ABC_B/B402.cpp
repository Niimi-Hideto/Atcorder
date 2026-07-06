#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> p;
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 1) {
            cin >> tmp;
            p.push_back(tmp);
        }
        else {
            cout << p.front() << endl;
            p.erase(p.begin());
        }
    }
}

// 【改善版】tmp をクエリ種別と X 値に使いまわさず分ける
// int query; cin >> query;
// if (query == 1) { int x; cin >> x; p.push_back(x); }
// else { cout << p.front() << endl; p.erase(p.begin()); }
