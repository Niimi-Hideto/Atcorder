#include <bits/stdc++.h>
using namespace std;

// 色を数字にする（白 = 0、赤 = 1、青 = 2）
int color_to_num(char ch) {
    if (ch == 'W') return 0;
    if (ch == 'R') return 1;
    return 2;  // 'B'
}

int main() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    // どの操作でも「2 枚の合計を 3 で割った余り」と「できた 1 枚の数」が一致する
    // → 全部のカードの合計を 3 で割った余りは、どんな順番で操作しても変わらない（不変量）
    // → 最後に残る 1 枚の数は、最初の合計を 3 で割った余りで決まる
    int sum = 0;
    for (char ch : s) {
        sum += color_to_num(ch);
    }

    cout << (sum % 3 == color_to_num(c) ? "Yes" : "No") << endl;
}
