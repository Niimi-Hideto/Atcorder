#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<vector<int>> tmp(n + 1);
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        tmp.at(i).push_back(l);

        for (int j = 1; j <= l; j++) {
            int a;
            cin >> a;
            tmp.at(i).push_back(a);
        }
    }

    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        long long c;
        cin >> c;

        cnt += tmp.at(i).at(0) * c;
        if (cnt >= k) {
            cnt -= tmp.at(i).at(0) * c;
            k -= cnt;

            if (k % tmp.at(i).at(0) == 0) {
                cout << tmp.at(i).at(tmp.at(i).at(0)) << endl;
            }
            else {
                cout << tmp.at(i).at(k % tmp.at(i).at(0)) << endl;
            }
            break;
        }
    }
}

// 改善点: tmp.at(i).at(0) * c を2回計算せず、先に判定してから足すかどうか決める
// long long block_len = tmp.at(i).at(0) * c;
// if (cnt + block_len >= k) {
//     k -= cnt;   // cntはこのブロックを含める前の値のまま使う
//
//     if (k % tmp.at(i).at(0) == 0) {
//         cout << tmp.at(i).at(tmp.at(i).at(0)) << endl;
//     }
//     else {
//         cout << tmp.at(i).at(k % tmp.at(i).at(0)) << endl;
//     }
//     break;
// }
// cnt += block_len;
