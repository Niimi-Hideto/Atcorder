#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }

    int r = 1;
    vector<int> ans(n);
    while (r <= n) {
        int tmp = 0;
        int use = 0;
        for (int i = 0; i < (int)p.size(); i++) {
            tmp = max(tmp, p.at(i));
        }
        for (int i = 0; i < (int)p.size(); i++) {
            if (p.at(i) == tmp) {
                ans.at(i) = r;
                use++;
            }
        }
        r += use;

        for (int i = 0; i < use; i++) {
            for (int j = 0; j < (int)p.size(); j++) {
                if (p.at(j) == tmp) {
                    p.at(j) = -1;
                    break;
                }
            }
        }
    }
    for (int x : ans) {
        cout << x << endl;
    }
}

// 【改善版】「自分より高い人の数 + 1」で一発
// for (int i = 0; i < n; i++) {
//     int rank = 1;
//     for (int j = 0; j < n; j++) {
//         if (p.at(j) > p.at(i)) rank++;
//     }
//     cout << rank << endl;
// }
