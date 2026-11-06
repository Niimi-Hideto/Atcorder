#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // vector<int> luc;  // 10 桁の数は最大 7777777777（約 7.8×10^9）で int に入らないので long long
    vector<long long> luc;

    // 10 桁の 4/7 の組み合わせ 1024 通りを全部作る
    for (int t = 0; t < (1 << 10); t++) {
        long long num = 0;
        // 上の桁（9 桁目）から順に 1 桁ずつ後ろに付け足していく
        for (int i = 9; i >= 0; i--) {
            if ((t >> i) & 1) {
                num = num * 10 + 7;  // i 桁目が 1 なら 7
            }
            else {
                num = num * 10 + 4;  // i 桁目が 0 なら 4
            }
        }
        luc.push_back(num);
    }

    // 小さい順に並べて、N 番目（0 始まりなので N − 1）を出す
    sort(luc.begin(), luc.end());
    cout << luc.at(n - 1) << endl;
}
