#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a.at(i) = i;
    }

    long long pos = 1;
    for (int query = 0; query < q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, x;
            cin >> p >> x;

            if (pos + p - 1 > n) {
                a.at((pos + p - 1) % n) = x;
            }
            else {
                a.at((pos + p - 1)) = x;
            }
        }
        else if (type == 2) {
            int p;
            cin >> p;

            if (pos + p - 1 > n) {
                cout << a.at((pos + p - 1) % n) << endl;
            }
            else {
                cout << a.at(pos + p - 1) << endl;
            }
        }
        else {
            long long k;
            cin >> k;

            k %= n;
            if (pos + k > n) {
                pos = (pos + k) % n;
            }
            else {
                pos += k;
            }
        }
    }
}

/* 改善点（変わる行だけ）

// 13行目：pos は 1〜N にしかならず、pos + k も約 10^9 で int に収まる
    int pos = 1;

// 1〜n で回すときは (x − 1) % n + 1（0 始まりにして % n、最後に 1 足して戻す）。if の場合分けがいらない
// 22〜27行目
            a.at((pos + p - 2) % n + 1) = x;

// 33〜38行目
            cout << a.at((pos + p - 2) % n + 1) << endl;

// 44〜50行目（k %= n もいらない。k は 10^9 以下なので int で読める）
            pos = (pos + k - 1) % n + 1;
*/
