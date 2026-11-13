#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    vector<long long> pre_a(n + 1);
    for (int i = 1; i <= n; i++) {
        pre_a.at(i) = pre_a.at(i - 1) + a.at(i);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (pre_a.at(n) - pre_a.at(i)) * a.at(i);
    }

    cout << ans << endl;
}

/* 別解（直すところではない。12〜20行目を、累積和の配列を作らずループ 1 つで書く形）

// 前から見て「自分より前の合計 sum」× a_i を足す（i < j の組を後ろ側 j から数える）
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sum * a.at(i);  // 先に足してから
        sum += a.at(i);        // 合計を増やす（順番を逆にすると自分どうしの積が入る）
    }
*/
