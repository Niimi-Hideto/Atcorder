#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ne;
    vector<int> po;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp > 0) {
            po.push_back(tmp);
        }
        else {
            ne.push_back(tmp);
        }
    }

    sort(po.begin(), po.end());
    sort(ne.rbegin(), ne.rend());

    long long position = 0;
    long long ans = 0;
    int j = 0;
    int k = -1;
    for (int i = 0; i < (int)po.size(); i++) {
        if (j < (int)ne.size()) {
            long long po_t = po.at(i) - position;
            long long ne_t = position - ne.at(j);

            if (po_t < ne_t) {
                position = po.at(i);
                ans += po_t;
            }
            else {
                position = ne.at(j);
                ans += ne_t;
                j++;
                i--;
            }
        }
        else {
            k = i;
            break;
        }
    }

    if (k != -1) {
        for (int i = k; i < (int)po.size(); i++) {
            long long po_t = po.at(i) - position;
            position = po.at(i);
            ans += po_t;
        }
    }
    else {
        for (int i = j; j < (int)ne.size(); j++) {
            long long ne_t = position - ne.at(j);
            position = ne.at(j);
            ans += ne_t;
        }
    }

    cout << ans << endl;
}

// 改善点: forループ内でi--して無理やりwhile的に動かすより、
// while2本（マージ＋残りを流し込む）の方がシンプルでkも不要になる
//
// long long position = 0, ans = 0;
// int i = 0, j = 0;
//
// while (i < (int)po.size() && j < (int)ne.size()) {
//     long long po_t = po.at(i) - position;
//     long long ne_t = position - ne.at(j);
//     if (po_t < ne_t) {
//         position = po.at(i);
//         ans += po_t;
//         i++;
//     }
//     else {
//         position = ne.at(j);
//         ans += ne_t;
//         j++;
//     }
// }
// while (i < (int)po.size()) {
//     ans += po.at(i) - position;
//     position = po.at(i);
//     i++;
// }
// while (j < (int)ne.size()) {
//     ans += position - ne.at(j);
//     position = ne.at(j);
//     j++;
// }
// cout << ans << endl;