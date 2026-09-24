#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    // pre.at(i) = 1〜i 番目の合計。最大 10^5 × 10^9 = 10^14 なので long long
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pre.at(i) = pre.at(i - 1) + x;
    }

    long long ans = 0;   // 答えは最大 N(N+1)/2 ≈ 5×10^9 なので long long

    // r = 左端 i から始めて、合計が K 以内になる一番右の番号。
    //     A_i 自体が K を超えるときは1個も買えないので r = i - 1
    int r = 0;
    for (int i = 1; i <= n; i++) {
        // 左端が右に進んだので、右端が左端より左にならないよう合わせる
        if (r < i - 1) {
            r = i - 1;
        }

        // 次の品物（r+1）まで含めても K 以内なら伸ばす。範囲チェックを先に書く
        while (r + 1 <= n && pre.at(r + 1) - pre.at(i - 1) <= k) {
            r++;
        }

        // 区間 [i, i], [i, i+1], …, [i, r] の r - i + 1 個（r = i - 1 なら 0 個）
        ans += r - i + 1;
    }

    cout << ans << endl;
}
