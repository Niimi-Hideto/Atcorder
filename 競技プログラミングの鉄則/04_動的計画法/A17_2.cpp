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
    dp.at(1) = 0;
    dp.at(2) = a.at(2);
    for (int i = 3; i <= n; i++) {
        dp.at(i) = min(dp.at(i - 1) + a.at(i), dp.at(i - 2) + b.at(i));
    }

    vector<int> ans;
    ans.push_back(n);

    int i = n;
    while (i > 1) {
        if (dp.at(i - 1) + a.at(i) == dp.at(i)) {
            ans.push_back(i - 1);
            i -= 1;
        }
        else {
            ans.push_back(i - 2);
            i -= 2;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

/* ===== 改善点 =====
   1. 26 行目の i は「今いる部屋」なので、for のループ番号と区別して pos などの名前にする
      （28〜34 行目が「今いる部屋から、どこへ戻るか」と読める）

   int pos = n;
   while (pos > 1) {
       if (dp.at(pos - 1) + a.at(pos) == dp.at(pos)) {
           ans.push_back(pos - 1);
           pos -= 1;
       }
       else {
           ans.push_back(pos - 2);
           pos -= 2;
       }
   }
*/
