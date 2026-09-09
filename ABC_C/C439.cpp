#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // cnt.at(v) = v を x^2 + y^2 (0<x<y) の形で表せる通り数
    // 値の範囲が 1〜N（≤10^7）に収まっているので、setではなく「配列の添字」で数える
    // ここが TLE の解消点（setだと1回ごとに木を辿るので数百万回で間に合わない）
    vector<int> cnt(n + 1, 0);

    // x < y なので x^2 + y^2 > 2*x^2。2*x^2 が n 以上になったらもう候補はない
    for (int i = 1; 2 * i * i < n; i++) {
        // y は x より大きいところから始める（x < y の条件）
        for (int j = i + 1; ; j++) {
            int tmp = i * i + j * j;
            // j は増える一方なので、n を超えたらこの i では以降すべて超える → 打ち切り
            if (tmp > n) {
                break;
            }
            cnt.at(tmp)++;
        }
    }

    // ちょうど1通りのものだけを集める（0通りも2通り以上も除外）
    vector<int> ans;
    for (int v = 1; v <= n; v++) {
        if (cnt.at(v) == 1) {
            ans.push_back(v);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans.at(i);
    }
    // k=0 のときも空行を出す必要があるので、ループの外で必ず改行する
    cout << endl;
}
