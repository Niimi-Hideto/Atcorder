#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（WA）=====
   ・flag が true になるのは「この i のループで j が 1 回でも伸びたとき」だけ。
     j が前の i で伸びきっていると、i+1〜j−1 に相方がいても足されない（例：4 2 / 1 2 3 10 で 2 を出力、正解は 3）
   ・j が「届く一番右」と「届かない最初の位置」のどちらを表すか決まっていないので、flag や j − i / j − i − 1 の場合分けが必要になっている

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int i = 0, j = 1;
    long long ans = 0;
    while (i < n - 1) {
        bool flag = false;
        while (true) {
            if (a.at(j) - a.at(i) <= k) {
                flag = true;
                if (j != n - 1) {
                    j++;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
        if (flag) {
            if (a.at(j) - a.at(i) <= k) {
                ans += j - i;
            }
            else {
                ans += j - i - 1;
            }
        }
        i++;
    }
    cout << ans << endl;
}
*/

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    // r：左端 i から見て、差が k 以内で届く「一番右」の位置
    int r = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        // 自分自身（差 0）までは必ず届くので、r が i より左なら i まで持ってくる
        if (r < i) {
            r = i;
        }
        // 次の r + 1 も届くなら伸ばす（範囲チェックを先に書く）
        while (r + 1 < n && a.at(r + 1) - a.at(i) <= k) {
            r++;
        }
        // 相方は i+1〜r の r − i 個
        ans += r - i;
    }
    cout << ans << endl;
}
