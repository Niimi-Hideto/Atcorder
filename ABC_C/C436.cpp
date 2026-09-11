#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        pair<int, int> rc;
        cin >> rc.first >> rc.second;

        bool ok = true;
        if (s.count(rc) == 1) {
            ok = false;
        }
        rc.first++;
        if (s.count(rc) == 1) {
            ok = false;
        }
        rc.first--;
        rc.second++;
        if (s.count(rc) == 1) {
            ok = false;
        }
        rc.first++;
        if (s.count(rc) == 1) {
            ok = false;
        }

        if (ok) {
            s.insert(rc);
            rc.first--;
            s.insert(rc);
            rc.second--;
            s.insert(rc);
            rc.first++;
            s.insert(rc);
            ans++;
        }
    }
    cout << ans << endl;
}

// 改善案：
// ①rc自体を ++ / -- で動かしながら4マスを回ると、1つ間違えただけで静かに壊れる。
//   (r,c) は固定して、オフセット(dr,dc)をループで回す形にすると読みやすい
//   （07-03に記録した「グリッドの4方向探索は di/dj でループする」と同じ考え方）：
//
//     int r, c;
//     cin >> r >> c;
//
//     bool ok = true;
//     for (int dr = 0; dr < 2; dr++) {
//         for (int dc = 0; dc < 2; dc++) {
//             if (s.count({r + dr, c + dc})) {
//                 ok = false;
//             }
//         }
//     }
//
//     if (ok) {
//         for (int dr = 0; dr < 2; dr++) {
//             for (int dc = 0; dc < 2; dc++) {
//                 s.insert({r + dr, c + dc});
//             }
//         }
//         ans++;
//     }
//
// ②set の count() は 0 か 1 しか返さないので、`== 1` は不要。if (s.count(rc)) で足りる
