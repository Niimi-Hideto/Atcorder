#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    vector<vector<int>> al(26, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            al.at(j).at(i + 1) = al.at(j).at(i);
        }
        al.at(s.at(i) - 'a').at(i + 1)++;
    }

    long long ans = 0;
    for (int i = l; i <= n; i++) {
        int lo = max(1, i - r);  // 下限をクランプ
        int hi = i - l;          // 上限
        if (hi < lo) continue;   // 有効な範囲がなければスキップ

        ans += (al.at(s.at(i - 1) - 'a').at(hi) - al.at(s.at(i - 1) - 'a').at(lo - 1));
    }
    cout << ans << endl;
}
