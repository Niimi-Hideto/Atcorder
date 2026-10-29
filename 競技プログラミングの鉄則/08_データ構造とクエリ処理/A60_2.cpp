#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        while (!s.empty() && s.top().first < a) {
            s.pop();
        }
        if (s.empty()) {
            cout << -1;
        }
        else {
            cout << s.top().second;
        }

        if (i != 1 || i != n) {
            cout << " ";
        }

        s.push({ a, i });
    }
    cout << endl;
}

/* ===== 改善点 =====
   1. i != 1 || i != n は、i が 1 と n に同時になれる N = 1 以外いつも true で、最後の数字のあとにも空白が出ている
      （AtCoder は行末の空白を無視するので通った）。|| は「どちらか 1 つでも成り立てば true」なので範囲は絞れない。
      2 つ目からは前に " " を出す形にすれば、条件は i >= 2 の 1 つで済む（16・23–25 行目）

        if (i >= 2) {                                  // 16 行目の前へ移す（23–25 行目は消す）
            cout << " ";
        }
*/
