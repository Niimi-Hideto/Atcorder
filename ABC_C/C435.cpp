#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    int domino = a.at(1) + 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (domino > i) {
            ans++;
            if (domino < a.at(i) + i) {
                domino = a.at(i) + i;
            }
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

// 改善案：①maxで1行にする ②終了条件をforの条件に出す ③変数名を実態（範囲の右端）に合わせる
//
//     int reach = a.at(1) + 1;   // 倒れる範囲の右端（この座標は含まない）
//     int ans = 1;
//     for (int i = 2; i <= n && reach > i; i++) {
//         ans++;
//         reach = max(reach, a.at(i) + i);   // 今までで一番遠いところまで伸ばす
//     }
//
// ①if で比較してから代入するより、max の方が「到達点は今までで一番遠いところ」という
//   意図が式そのものに表れる
// ②else break でループを抜けるより、for の条件に書いた方が「いつ終わるか」が先頭で読める
//   （iは毎回必ず進むのでforが適切、という判断自体は合っている：08-15のノートの基準）
// ③domino という名前だが中身は「ドミノ」ではなく「倒れる範囲の右端（座標）」。
//   reach / right の方が実態に合う（C445の last と同じで、名前と中身のズレは後で混乱する）
