#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> c(h);
    for (int i = 0; i < h; i++) {
        cin >> c.at(i);
    }

    int black = 0;
    vector<int> row(h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c.at(i).at(j) == '.') {
                row.at(i)++;
            }
            if (c.at(i).at(j) == '#') {
                black++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << h); i++) {
        vector<string> c_cp = c;
        int cnt = 0, tmp = 0;
        for (int j = 0; j < h; j++) {
            if ((i >> j) & 1) {
                tmp += row.at(j);
                c_cp.at(j) = string(w, '#');
                cnt++;
            }
        }

        if (cnt < k) {
            vector<int> col(w);
            for (int l = 0; l < w; l++) {
                for (int m = 0; m < h; m++) {
                    if (c_cp.at(m).at(l) == '.') {
                        col.at(l)++;
                    }
                }
            }
            sort(col.rbegin(), col.rend());

            for (int n = 0; n < (k - cnt); n++) {
                tmp += col.at(n);
            }
        }

        if (cnt > k) continue;
        ans = max(ans, tmp + black);
    }
    cout << ans << endl;
}

/* 改善点（変わる行だけ）

// ① 54行目の continue は、cnt を数え終わった直後（36行目のあと）に移す。行を選びすぎたら列の計算をせずに飛ばせる
        if (cnt > k) continue;

// ② 38行目の if (cnt < k) と 52行目の } を消す。cnt == k なら 49行目のループが 0 回で終わるだけ

// ③ 13〜24行目（row・black）と 32行目（tmp += row.at(j)）を消す。
//    行を塗ったあとの c_cp の # を、列を数えるループで一緒に数える。55行目は tmp + black ではなく tmp だけ
            for (int x = 0; x < w; x++) {
                for (int y = 0; y < h; y++) {
                    if (c_cp.at(y).at(x) == '.') {
                        col.at(x)++;
                    }
                    else {
                        tmp++;
                    }
                }
            }
        ans = max(ans, tmp);

// ④ 40・41行目のループ変数は役割で名前を付ける（列は x、行は y。③のコードがその形）
*/
