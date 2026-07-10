#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        int count = 0;
        long long tmp_ans = ans;
        while (tmp_ans > 0) {
            tmp_ans /= 10;
            count++;
        }
        long long tmp = a;
        for (int j = 0; j < 19 - count; j++) {
            tmp /= 10;
        }
        if (tmp > 0) {
            ans = 1;
            continue;
        }

        ans *= a;
        tmp = ans;
        for (int j = 0; j < k; j++) {
            tmp /= 10;
        }
        if (tmp > 0) {
            ans = 1;
        }
    }
    cout << ans << endl;
}

// 【改善版】10^K を limit として先に計算し、除算でオーバーフロー安全に比較
// long long limit = 1;
// for (int i = 0; i < k; i++) limit *= 10;   // 10^K（K≤18なのでlong longに収まる）
//
// long long ans = 1;
// for (int i = 0; i < n; i++) {
//     long long a; cin >> a;
//     if (a > (limit - 1) / ans) {            // ans * a >= limit になるか事前チェック
//         ans = 1;                             // （掛けずに判定するのでオーバーフローしない）
//     } else {
//         ans *= a;
//     }
// }
// cout << ans << endl;
