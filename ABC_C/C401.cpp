#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n < k) {
        cout << 1 << endl;
        return 0;
    }

    long long ak;
    vector<long long> a(n + 1, 1);
    for (int i = k; i <= n; i++) {
        if (i == k) {
            ak = k;
        }
        else {
            ak -= a.at(i - k - 1);
            ak += a.at(i - 1);
        }

        if (ak < 0) ak += 1000000000;
        ak %= 1000000000;
        a.at(i) = ak;
    }
    cout << a.at(n) << endl;
}

/* 改善点（変わる行だけ）

// ① 8〜11行目はいらない：n < k ならループが 1 回も回らず、a.at(n) は初期値の 1 のまま

// ② 割る数に名前を付ける（24・25行目の 1000000000 を MOD に）
    const long long MOD = 1000000000;
        if (ak < 0) ak += MOD;
        ak %= MOD;

// ③ ループ 1 回目だけの if（16〜18行目）をなくす形。ただし a.at(k) は n ≥ k のときしかないので、
//    ③ を使うなら 8〜11行目は残す（① と ③ はどちらか一方）
    long long ak = k;
    a.at(k) = k;
    for (int i = k + 1; i <= n; i++) {
        ak -= a.at(i - k - 1);
        ak += a.at(i - 1);
        ...
*/
