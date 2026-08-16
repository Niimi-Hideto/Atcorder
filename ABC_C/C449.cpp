//解けなかった．

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    vector<vector<int>> cnt(26, vector<int>(n + 1, 0));
    for (int k = 1; k <= n; k++) {
        int c = s.at(k - 1) - 'a';
        for (int ch = 0; ch < 26; ch++) {
            cnt.at(ch).at(k) = cnt.at(ch).at(k - 1);
        }
        cnt.at(c).at(k)++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = s.at(i - 1) - 'a';
        int lo = i + l;
        int hi = min(n, i + r);

        if (lo <= hi) {
            ans += cnt.at(c).at(hi) - cnt.at(c).at(lo - 1);
        }
    }

    cout << ans << endl;
}
