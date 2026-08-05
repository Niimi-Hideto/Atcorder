#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i).at(0) >> vec.at(i).at(1);
    }
    sort(vec.begin(), vec.end());

    int y = n + 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = y;
        y = min(y, vec.at(i).at(1));
        if (tmp != y) {
            ans++;
        }
    }
    cout << ans << endl;
}

// 改善点: vector<vector<int>> の2要素固定なら pair<int,int> の方がスッキリ
// vector<pair<int,int>> vec(n); // {X, Y}
// cin >> vec.at(i).first >> vec.at(i).second;
// sort(vec.begin(), vec.end()); // firstの昇順でそのままソートできる
