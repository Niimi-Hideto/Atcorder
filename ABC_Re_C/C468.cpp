#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> q.at(i);
    }

    int ans = 0;
    if (p >= q) {
        cout << ans << endl;
        return 0;
    }
    else {
        while (p < q) {
            next_permutation(p.begin(), p.end());
            ans++;
        }

        cout << ans - 1 << endl;
    }
}

/* 改善点（変わる行だけ）

// ① 21行目の else { と 28行目の } を消す。17行目の if の中で return 0; しているので、if を通り過ぎた時点でもう p < q。
//    22〜27行目は1段浅くなる
    while (p < q) {
        next_permutation(p.begin(), p.end());
        ans++;
    }
    cout << ans - 1 << endl;

// ② 18行目：ans はまだ 0 なので、0 と直接書いたほうが意味が伝わる
        cout << 0 << endl;
*/
