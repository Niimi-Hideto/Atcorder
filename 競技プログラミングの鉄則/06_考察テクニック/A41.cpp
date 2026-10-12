#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（WA）=====
   ・「ダメそうな形（先頭・末尾の RBRB）」を見つけるたびにはじく作りで、まだ見つかっていないダメな形が残る
   ・N = 3 のとき s.at(3) は範囲外

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool ok = true;
    if (s.at(0) == s.at(2) && s.at(0) != s.at(1) && s.at(1) == s.at(3)) {
        if (n - 4 < 3) {
            ok = false;
        }
    }
    if (s.at(n - 1) == s.at(n - 3) && s.at(n - 1) != s.at(n - 2) && s.at(n - 2) == s.at(n - 4)) {
        if (n - 4 < 3) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
*/

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 最後に塗った 3 枚は上から塗られないので、完成形には必ず「同じ色が 3 つ連続」が残る（必要）
    // 逆にそれがあれば、そこを最後に塗り、左側は左端から・右側は右端から 3 枚ずつ塗っていけば作れる（十分）
    bool ok = false;
    for (int i = 0; i + 2 < n; i++) {
        if (s.at(i) == s.at(i + 1) && s.at(i + 1) == s.at(i + 2)) {
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
