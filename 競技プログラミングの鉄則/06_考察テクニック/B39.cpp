#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;


    vector<priority_queue<int>> q(d + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        q.at(x).push(y);
    }

    int ans = 0;
    for (int i = 1; i <= d; i++) {

        int mx = 0;
        for (int j = 1; j <= i; j++) {
            if (!q.at(j).empty()) {
                mx = max(mx, q.at(j).top());
            }
        }
        for (int j = 1; j <= i; j++) {
            if (!q.at(j).empty() && q.at(j).top() == mx) {
                q.at(j).pop();
                break;
            }
        }

        ans += mx;
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 最大を探すループと、その最大を探して pop するループで同じ範囲を 2 回回している。
      最大を探すときに「どの山の top だったか」（best）も覚えておけば、2 つ目のループと == mx の比較が要らない（21〜32 行目）

   int mx = 0, best = -1;                                  // 21〜32 行目
   for (int j = 1; j <= i; j++) {
       if (!q.at(j).empty() && q.at(j).top() > mx) {
           mx = q.at(j).top();
           best = j;
       }
   }
   if (best != -1) {
       q.at(best).pop();
   }
*/
