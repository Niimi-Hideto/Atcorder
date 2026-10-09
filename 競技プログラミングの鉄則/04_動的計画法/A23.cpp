#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（途中）=====
   ・列を「品物 j」にして、品物ごとに別々に true / false を持っていた。
     これだと「どの品物の組み合わせがそろっているか」と「何枚使ったか」が表に入らない
   ・行＝クーポン i まで使うか決めた、は合っていた

int main() {
    int n, m;
    cin >> n >> m;


    vector<vector<int>> a(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a.at(i).at(j);
        }
    }

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp.at(0).at(0) = true;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);

            if (dp.at(i).at(j)) continue;

            if (a.at(i).at(j)) dp.at(i).at(j) = true;
        }
    }

    bool ok = true;
    for (int j = 0; j <= n; j++) {
        if (!dp.at(m).at(j)) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
*/

int main() {
    int n, m;
    cin >> n >> m;

    // mask.at(i)：クーポン i で無料になる品物の集合を、2 進数の 1 つの整数で表したもの
    // 品物を 0 番目から数えて、k 番目の品物が対象なら、k 桁目（重さ 2^k）を 1 にする
    // 例：n = 3 で入力が「1 0 1」なら、0 桁目と 2 桁目が 1 → 2 進数 101 → mask = 1 + 4 = 5
    vector<int> mask(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        for (int k = 0; k < n; k++) {
            int x;
            cin >> x;
            if (x == 1) {
                mask.at(i) += (1 << k);  // k 桁目の重さ 2^k を足す
            }
        }
    }

    // dp.at(i).at(s)：クーポン 1〜i まで使うか決めて、そろった品物の集合が s になる最小枚数
    int INF = 1000000000;
    int full = (1 << n) - 1;  // 全部の品物がそろった集合（n 桁全部が 1）
    vector<vector<int>> dp(m + 1, vector<int>(full + 1, INF));
    dp.at(0).at(0) = 0;  // 何も使っていなければ、そろった品物はなし

    for (int i = 1; i <= m; i++) {
        for (int s = 0; s <= full; s++) {
            if (dp.at(i - 1).at(s) == INF) {
                continue;  // この集合にはまだたどり着けない
            }
            // クーポン i を使わない：集合も枚数もそのまま
            dp.at(i).at(s) = min(dp.at(i).at(s), dp.at(i - 1).at(s));
            // クーポン i を使う：集合に OR で品物を足し、枚数は +1（配る形）
            int t = s | mask.at(i);
            dp.at(i).at(t) = min(dp.at(i).at(t), dp.at(i - 1).at(s) + 1);
        }
    }

    if (dp.at(m).at(full) == INF) {
        cout << -1 << endl;
    }
    else {
        cout << dp.at(m).at(full) << endl;
    }
}
