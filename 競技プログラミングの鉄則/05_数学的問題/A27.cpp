#include <bits/stdc++.h>
using namespace std;

// ユークリッドの互除法
// 「大きいほうを小さいほうで割った余りに置き換えても、最大公約数は変わらない」を繰り返す。
// 例：gcd(117, 45) → 117 % 45 = 27 → gcd(27, 45) → 45 % 27 = 18 → gcd(27, 18)
//     → 27 % 18 = 9 → gcd(9, 18) → 18 % 9 = 0 → gcd(9, 0) → 答え 9
// どちらかが 0 になったら、残ったほうが最大公約数。
// 1回ごとに大きいほうが半分以下になるので、10^9 でも 60 回程度で終わる
int gcd_euclid(int a, int b) {
    while (a >= 1 && b >= 1) {
        if (a >= b) {
            a = a % b;   // 大きいほう a を、余りに置き換える
        }
        else {
            b = b % a;   // 大きいほう b を、余りに置き換える
        }
    }
    // どちらかが 0 になっている。0 でないほうが答え
    if (a != 0) {
        return a;
    }
    return b;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd_euclid(a, b) << endl;
}
