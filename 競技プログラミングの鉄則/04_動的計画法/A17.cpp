#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a.at(i);
    }
    for (int i = 3; i <= n; i++) {
        cin >> b.at(i);
    }

    vector<int> dp(n + 1);
    dp.at(2) = a.at(2);
    for (int i = 3; i <= n; i++) {
        dp.at(i) = min(dp.at(i - 2) + b.at(i), dp.at(i - 1) + a.at(i));
    }

    // 答えの復元：ゴール N から部屋 1 まで逆にたどる
    // 部屋 p に最短で来たなら、直前の部屋からの道で dp[p] の値がちょうど出るはず
    vector<int> route;
    int p = n;
    while (true) {
        route.push_back(p);
        if (p == 1) {
            break;
        }

        if (dp.at(p - 1) + a.at(p) == dp.at(p)) {
            p = p - 1;   // p-1 から来た
        }
        else {
            p = p - 2;   // p-2 から来た
        }
    }

    // route はゴールからの順番になっているので、逆順にしてスタートからにする
    reverse(route.begin(), route.end());

    cout << route.size() << endl;
    for (int i = 0; i < (int)route.size(); i++) {
        cout << route.at(i) << (i == (int)route.size() - 1 ? "\n" : " ");
    }
}
