#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（範囲外）=====
   ・36 行目 prea.at(n + 1)：prea のサイズは n + 1 なので使える添字は 0〜n。n + 1 は 1 つ外側
   ・27〜29 行目：crt がちょうど n のときは割らないので crt = n が残り、39 行目の l + crt − 1 が n を超える（crt %= n は毎回やる）
   ・先頭に戻る場合を「後ろの部分＋前の部分」に分ける考え方は正しい別解だが、l も先頭に戻る場合まで含めると場合分けが増える
   ・その前の版（配列を伸ばす・deque で実際に回す）は、クエリ 1 のたびに c 回ループして最悪 4×10^10 回で MLE / TLE

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> prea(n + 1);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    for (int i = 1; i <= n; i++) {
        prea.at(i) = prea.at(i - 1) + a.at(i);
    }

    int crt = 0;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int c;
            cin >> c;

            crt += c;
            if (crt > n) {
                crt %= n;
            }
        }
        else {
            int l, r;
            cin >> l >> r;

            if (r + crt > n) {
                cout << prea.at(n + 1) - prea.at(l + crt - 1) + prea.at(crt) << endl;
            }
            else {
                cout << prea.at(r + crt) - prea.at(l + crt - 1) << endl;
            }
        }
    }
}
*/

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    // A を 2 つつなげた長さ 2N の配列の累積和
    // i 番目（1〜2N）の値は a.at((i - 1) % n + 1)
    vector<long long> pre(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        pre.at(i) = pre.at(i - 1) + a.at((i - 1) % n + 1);
    }

    int crt = 0;  // 合計で何回回したか（N で割った余り）
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int c;
            cin >> c;
            crt = (crt + c) % n;  // N 回で元に戻るので余りだけ持つ
        }
        else {
            int l, r;
            cin >> l >> r;
            // 今の l〜r 番目 ＝ つなげた配列の (l + crt)〜(r + crt) 番目（r + crt < 2N なのではみ出さない）
            cout << pre.at(r + crt) - pre.at(l + crt - 1) << endl;
        }
    }
}
