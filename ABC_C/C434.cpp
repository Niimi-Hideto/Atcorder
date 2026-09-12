#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n;
        long long h;
        cin >> n >> h;

        // 「その時刻に取りうる高度の範囲」を1つの区間 [lo, hi] として持ち回す
        // 時刻0では高度Hに確定しているので、幅0の区間から始まる
        long long lo = h, hi = h;
        long long prev = 0;      // 直前に見た時刻
        bool ok = true;

        for (int i = 0; i < n; i++) {
            long long ti, li, ui;
            cin >> ti >> li >> ui;

            long long dt = ti - prev;   // 前の時刻からの経過時間

            // 1秒あたり±1まで変化できるので、取りうる範囲は上下にdtずつ広がる
            // hi+dt は最大 10^9+10^9 = 2×10^9 で int の上限に近いので long long で持つ
            hi += dt;
            lo -= dt;

            // 高度は0以下にできない。目標の下限 l_i は必ず1以上なので、
            // loを1で打ち切っても判定結果は変わらない（1より下にいられても得はしない）
            if (lo < 1) {
                lo = 1;
            }

            // この時刻の目標 [li, ui] との共通部分を取る
            lo = max(lo, li);
            hi = min(hi, ui);

            // 共通部分が空 → この目標は達成できない
            if (lo > hi) {
                ok = false;
            }

            prev = ti;
        }
        // 注意：okがfalseになっても途中でbreakしない。
        // 残りの入力を読み切らないと、次のテストケースの読み込みがずれる

        cout << (ok ? "Yes" : "No") << endl;
    }
}
