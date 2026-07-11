#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> vc(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> vc.at(i).at(1) >> vc.at(i).at(0);
    }
    sort(vc.rbegin(), vc.rend());

    long long ans = 0;
    int cnt = 0;
    vector<int> color(n);
    for (int i = 0; i < n; i++) {
        if (color.at(vc.at(i).at(1) - 1) == 0) {
            ans += vc.at(i).at(0);
            color.at(vc.at(i).at(1) - 1)++;
            vc.at(i).at(0) = 0;
            cnt++;
        }
        if (cnt == m) {
            break;
        }
    }

    if (k > m) {
        for (int i = 1; i < n; i++) {
            if (vc.at(i).at(0) != 0) {
                ans += vc.at(i).at(0);
                vc.at(i).at(0) = 0;
                cnt++;
            }
            if (cnt == k) {
                break;
            }
        }
    }
    cout << ans << endl;
}

// 改善点: vector<vector<int>> の2要素固定なら pair<int,int> の方がスッキリ
// vector<pair<int,int>> vc(n); // {value, color}
// cin >> vc.at(i).second >> vc.at(i).first;
// sort(vc.rbegin(), vc.rend()); // first(value)の降順でそのまま降順ソートできる
