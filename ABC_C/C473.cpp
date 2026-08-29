#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cl(k);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        tmp -= 1;

        cl.at(tmp) = cl.at(tmp) + 1;
    }

    sort(cl.rbegin(), cl.rend());

    int ans = 1;
    int i = 1;
    int max = cl.at(0);
    while (k > 1) {
        if (i < k && cl.at(i) == max) {
            i++;
            ans++;
            continue;
        }
        else if (i < k && cl.at(i) + 1 == max) {
            i++;
            ans++;
            continue;
        }
        break;
    }

    cout << ans << endl;
}

// 改善案：
// ①`max`はstd::maxと名前が被るので`max_val`などに変える
// ②whileの条件をkでなくiで管理すれば、if内の`i < k &&`が不要になる
//
// int ans = 1;
// int i = 1;
// int max_val = cl.at(0);
// while (i < k) {
//     if (cl.at(i) == max_val) {
//         i++;
//         ans++;
//     }
//     else if (cl.at(i) + 1 == max_val) {
//         i++;
//         ans++;
//     }
//     else {
//         break;
//     }
// }
