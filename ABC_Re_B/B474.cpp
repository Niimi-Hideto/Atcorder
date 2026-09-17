#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        // i番目に退場した人が属するグループ番号（切り上げの割り算）
        // 1〜10番目→1、11〜20番目→2、21〜25番目→3
        int g = (i + 9) / 10;

        // グループgの人は座席 (g-1)*10+1 〜 g*10 のはず。
        // 上限だけ見れば十分（Pは順列なので、グループ1が全部10以下なら
        // 中身は必ず{1..10}に確定し、以降も帰納的に決まるため）
        if (p > g * 10) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
