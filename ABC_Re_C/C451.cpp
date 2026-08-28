#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<int> t;

    for (int i = 0; i < q; i++) {
        int k, h;
        cin >> k >> h;

        if (k == 1) {
            t.insert(h);
        }
        else {
            while (true && t.size() > 0) {
                int tmp = *begin(t);
                if (tmp > h) {
                    break;
                }
                t.erase(tmp);
            }
        }
        cout << t.size() << endl;
    }
}

// 改善案：18行目の while (true && t.size() > 0) は `true &&` が冗語
// while (!t.empty()) で十分（もしくは while (t.size() > 0) だけでもOK）
