#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int tmp = 0;
    long long time = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (i == 0) {
            time += a;
            tmp = a;
        }
        else {
            if (a - tmp > 100) {
                time += (a - tmp) - 100;
                tmp = a;
            }
        }
    }

    if (t - tmp > 100) {
        time += (t - tmp) - 100;
    }

    cout << (n == 0 ? t : time) << endl;
}

// 改善案：変数名`time`はstd::time()と被るので`ans`などに変える（`t`はTで使用済み）
//
// int tmp = 0;
// long long ans = 0;
// ...
// ans += a; / ans += (a - tmp) - 100;
// ...
// cout << (n == 0 ? t : ans) << endl;
