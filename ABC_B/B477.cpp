#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x.at(i).first;
        x.at(i).second = i;
    }

    sort(x.begin(), x.end());

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (x.at(i + 1).first - x.at(i).first >= d) {
                ans.push_back(x.at(i).second);
            }
        }
        else if (i == n) {
            if (x.at(i).first - x.at(i - 1).first >= d) {
                ans.push_back(x.at(i).second);
            }
        }
        else {
            if (x.at(i).first - x.at(i - 1).first >= d
                && x.at(i + 1).first - x.at(i).first >= d) {
                ans.push_back(x.at(i).second);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

/* ===== 改善点 =====
   1. N ≤ 100 なので、全員と全員を比べても 10^4 回。問題文の定義をそのまま書けば、
      pair で番号を覚える・両端の場合分け・最後の sort(ans) が全部いらなくなる
      （N が極端に小さい問題は、賢い省略より間違えにくい書き方を優先する。ABC474 B と同じ）

   vector<int> x(n);
   for (int i = 0; i < n; i++) {
       bool ok = true;
       for (int j = 0; j < n; j++) {
           if (j != i && abs(x.at(i) - x.at(j)) < d) ok = false;
       }
       if (ok) ans.push_back(i + 1);   // 番号順に回すので最初から昇順
   }
*/
