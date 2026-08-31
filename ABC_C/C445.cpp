#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    // final.at(i) = マスiから駒を動かし続けたときに最終的にたどり着く不動点
    // 0は「まだ計算してない」の印（マス番号は1以上なので0とは絶対に被らない）
    vector<int> final_pos(n + 1, 0);

    // iを大きい方から処理する。A_i > i なので、A_i側は必ずiより先(大きい側)に処理済みになる
    for (int i = n; i >= 1; i--) {
        if (a.at(i) == i) {
            // 自分自身に戻ってくる＝ここが不動点
            final_pos.at(i) = i;
        }
        else {
            // A_i > i なので final_pos.at(a.at(i)) はもう計算済み。それをそのまま使い回す
            final_pos.at(i) = final_pos.at(a.at(i));
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << final_pos.at(i) << " ";
    }
    cout << endl;
}
