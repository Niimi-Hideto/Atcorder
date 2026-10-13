#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a.at(i) = i;
    }

    bool flip = false;
    for (int query = 0; query < q; query++) {
        int num;
        cin >> num;

        if (num == 1) {
            int x, y;
            cin >> x >> y;

            if (!flip) {
                a.at(x) = y;
            }
            else {
                a.at(n - x + 1) = y;
            }
        }
        else if (num == 2) {
            flip = !flip;
        }
        else {
            int x;
            cin >> x;

            if (!flip) {
                cout << a.at(x) << endl;
            }
            else {
                cout << a.at(n - x + 1) << endl;
            }
        }
    }
}

/* ===== 改善点 =====
   1. 「反転しているかで添字を読み替える」処理が 2 か所（22〜27 行目・36〜41 行目）にあるので、1 回だけ計算する
   2. num の中身は操作の種類なので type にする（15・16・18・29 行目）

   int pos = flip ? n - x + 1 : x;   // 反転しているなら、元の配列の n − x + 1 番目
   a.at(pos) = y;                    // 22〜27 行目
   cout << a.at(pos) << endl;        // 36〜41 行目
*/
