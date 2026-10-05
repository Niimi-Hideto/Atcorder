#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    // dp.at(i)：石が i 個で自分の手番のとき、勝ちなら true、負けなら false
    vector<bool> dp(n + 1);

    // 石の少ないほうから決める（i − a 個・i − b 個の結果はもう分かっている）
    for (int i = 0; i <= n; i++) {
        if (i >= a && dp.at(i - a) == false) {
            dp.at(i) = true;   // a 個取って、相手に負けの状態を渡せる
        }
        else if (i >= b && dp.at(i - b) == false) {
            dp.at(i) = true;   // b 個取って、相手に負けの状態を渡せる
        }
        else {
            dp.at(i) = false;  // どう取っても相手が勝つ（または取れない）
        }
    }

    // 最初の手番は先手
    if (dp.at(n)) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}
