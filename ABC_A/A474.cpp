#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x == 1) {
        cout << 2 << endl;
    }
    else if (x == 2) {
        cout << 3 << endl;
    }
    else if (x == 3) {
        cout << 1 << endl;
    }
}

// 改善案：
// ①剰余で巡回させれば1行で書ける（1→2, 2→3, 3→1）
//   cout << x % 3 + 1 << endl;
//   ABC420 A の (X+Y-1)%12+1（12ヶ月の巡回）と同じパターン
// ②最後の else if (x == 3) は、制約でXは1〜3と保証されてるので単に else でよい
//   （else if だと、万一それ以外の値が来たとき何も出力されない形になる）
