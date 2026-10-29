#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> work(d + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        work.at(x).push_back(y);
    }

    priority_queue<int> q;
    int ans = 0;
    for (int i = 1; i <= d; i++) {
        for (int x : work.at(i)) {
            q.push(x);
        }

        if (q.empty()) continue;
        ans += q.top();
        q.pop();
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 19 行目の x の中身は報酬 Y。入力では X が日付なので、x だと日付に見える。13 行目と同じ y にそろえる

        for (int y : work.at(i)) {                     // 19–21 行目
            q.push(y);
        }

   ※ ans は最大 D × Y = 2000 × 10^6 = 2×10^9 で、int の上限（約 2.1×10^9）にぎりぎり収まるので int のままで正しい。
     迷ったら long long でいい
*/
