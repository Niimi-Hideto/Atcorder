#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int ans = 0;
    int j = 0;  // ネタのポインタ（外に出して持ち回す）

    for (int i = 0; i < n; i++) {
        // 現在の最小ネタが今のシャリに乗せられるならマッチ
        if (j < m && b.at(j) <= 2 * a.at(i)) {
            ans++;
            j++;  // このネタは使った → 次のネタへ
        }
        // 乗せられなければ b[j] 以降は全部重すぎる（昇順なので）
        // → このシャリは詰んでいる → i++ で次のシャリへ（forが自動でやる）
    }
    cout << ans << endl;
}
