#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    vector<int> table(n + 1);
    for (int x = 1; x <= sqrt(n); x++) {
        for (int y = x + 1; ; y++) {
            if (x * x + y * y <= n) {
                int tmp = x * x + y * y;
                if (table.at(tmp) == 0) {
                    ans++;
                    table.at(tmp) = tmp;
                }
                else if (table.at(tmp) == -1) {
                    continue;
                }
                else {
                    table.at(tmp) = -1;
                    ans--;
                }
            }
            else {
                break;
            }
        }
    }

    cout << ans << endl;
    for (int x : table) {
        if (x > 0) {
            cout << x << " ";
        }
    }
    cout << endl;
}

/* ===== 改善版（今の知識範囲での書き方）=====

   直した4点
   1. 状態を「値そのもの(tmp)や-1」ではなく「通り数」で持つ。添字がすでに値なので
      値を格納する必要がない。ansの++/--という増減管理も消せる（最後に数えるだけ）
   2. sqrt(n)をループ条件に書かない。x<yなのでx²+y²>2x²。整数のまま範囲が決まり
      浮動小数点の誤差を気にしなくてよくなる
   3. x*x + y*y を先にtmpに入れて、計算を1回だけにする
   4. 不要なcontinueを消す

int main() {
    int n;
    cin >> n;

    // cnt.at(v) = v を x²+y²（0<x<y）で表せる通り数。
    // 2で打ち止めにする（「2通り」と「3通り以上」を区別する必要がないので）
    vector<int> cnt(n + 1, 0);

    // x < y なので x² + y² > 2x²。これでsqrtを使わずに範囲を決められる
    for (int x = 1; x * x * 2 < n; x++) {
        for (int y = x + 1; ; y++) {
            int tmp = x * x + y * y;
            if (tmp > n) {
                break;
            }
            if (cnt.at(tmp) < 2) {
                cnt.at(tmp)++;
            }
        }
    }

    // 増減させずに、最後に「ちょうど1通り」のものを集める
    vector<int> good;
    for (int i = 1; i <= n; i++) {
        if (cnt.at(i) == 1) {
            good.push_back(i);
        }
    }

    cout << good.size() << endl;
    for (int v : good) {
        cout << v << " ";
    }
    cout << endl;
}

===== ここまで ===== */
