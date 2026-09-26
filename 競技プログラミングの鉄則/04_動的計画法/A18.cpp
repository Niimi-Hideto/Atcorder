#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    // 選び方は 2^N 通りあるが、作れる合計は 0〜S の S+1 通りしかない。
    // 違う選び方でも合計が同じなら、この先の判定には同じなので「作れるか」だけ覚える
    // dp.at(i).at(j) = 最初の i 枚から何枚か選んで、合計をちょうど j にできるか
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp.at(0).at(0) = true;   // 1枚も選ばなければ合計 0 は作れる

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            // カード i を使わない：最初の i-1 枚で j が作れればいい
            bool ok = dp.at(i - 1).at(j);

            // カード i を使う：最初の i-1 枚で j - A_i が作れればいい
            if (j >= a.at(i) && dp.at(i - 1).at(j - a.at(i))) {
                ok = true;
            }

            dp.at(i).at(j) = ok;
        }
    }

    cout << (dp.at(n).at(s) ? "Yes" : "No") << endl;
}
