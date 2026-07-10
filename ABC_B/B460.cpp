#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long dx = x2 - x1;                    // 中心間のx差
        long long dy = y2 - y1;                    // 中心間のy差
        long long d2 = dx * dx + dy * dy;          // 中心間距離の二乗（sqrt不要）
        long long sum2 = (r1 + r2) * (r1 + r2);   // (R1+R2)の二乗
        long long dif2 = (r1 - r2) * (r1 - r2);   // |R1-R2|の二乗（二乗するので絶対値不要）

        // d >= |R1-R2| かつ d <= R1+R2 のとき共有点あり
        cout << (dif2 <= d2 && d2 <= sum2 ? "Yes" : "No") << endl;
    }
}
