#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // X座標を添字として Y座標を格納（X は 1〜N の順列なのでそのまま使える）
    vector<int> y_by_x(n + 1);
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        y_by_x.at(xi) = yi;
    }

    int y_min = n + 1;  // N+1 にすることで最初の点が必ずカウントされる
    int ans = 0;

    // X=1, 2, ..., N の順に処理
    for (int x = 1; x <= n; x++) {
        // これまでの Y の最小値より今の Y が小さければ条件を満たす
        if (y_min > y_by_x.at(x)) ans++;
        // Y_min を更新（チェックの後に行う）
        y_min = min(y_min, y_by_x.at(x));
    }

    cout << ans << endl;
}
