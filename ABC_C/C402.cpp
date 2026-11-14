#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> k(m + 1);
    vector<vector<int>> a(n + 1);

    for (int i = 1; i <= m; i++) {
        cin >> k.at(i);

        for (int j = 1; j <= k.at(i); j++) {
            int tmp;
            cin >> tmp;

            a.at(tmp).push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;

        for (int x : a.at(b)) {
            k.at(x)--;
            if (k.at(x) == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}

/* 改善点（変わる行だけ。名前を変えるので、使っている 12・14・18・27・28・29行目も合わせて変わる）

// 8行目：途中から「その料理に残っている苦手な食材の数」になるので rest
    vector<int> rest(m + 1);

// 9行目：中身は「食材ごとの、使われている料理の番号」なので dishes
    vector<vector<int>> dishes(n + 1);
*/
