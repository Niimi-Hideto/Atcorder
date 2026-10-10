#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == '1') {
            cnt++;
        }
    }

    bool ok = false;
    if (cnt >= k) {
        if ((cnt - k) % 2 == 0) {
            ok = true;
        }
    }
    else {
        if ((k - cnt) % 2 == 0) {
            ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. cnt >= k と cnt < k で分けているが、どちらも「差が偶数か」を見ているだけなので、abs で 1 行にまとまる（17〜27 行目）

   bool ok = (abs(cnt - k) % 2 == 0);
*/
