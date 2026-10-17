#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // ニム：全部の山の石の数の XOR が 0 なら後手の勝ち、0 でなければ先手の勝ち（暗記してよい結論）
    // ・XOR が 0 の状態からは、どう取っても XOR は 0 でなくなる
    // ・XOR が 0 でない状態からは、うまく取れば必ず XOR を 0 にできる
    // → XOR が 0 でない人は、相手に「XOR が 0 の状態」を渡し続けられ、最後に全部 0 を渡された相手が負け
    int x = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x ^= a;  // XOR は ^（2 進数で桁ごとに、1 が奇数個なら 1、偶数個なら 0）
    }

    cout << (x != 0 ? "First" : "Second") << endl;
}
