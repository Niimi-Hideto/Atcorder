#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, r;
    cin >> b >> r;

    int ans = 30 * 30;
    ans -= 30 * b;
    ans -= (30 - b) * r;

    cout << ans << endl;
}

/* 改善点（変わる行だけ）

// 引いていく形ではなく、残る大きさ（縦 30 − B 行 × 横 30 − R 列）をそのまま掛ける（8〜10行目）
    int ans = (30 - b) * (30 - r);
*/
