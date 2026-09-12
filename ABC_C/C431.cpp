#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> h.at(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }

    sort(h.begin(), h.end());
    sort(b.begin(), b.end());

    int j = 0;
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (h.at(i) > b.at(j)) {
                j++;
            }
            else {
                cnt++;
                j++;
                break;
            }
        }
        if (cnt == k) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

// 改善案：
// ①内側のwhileが「小さすぎる体を捨てる」と「マッチして数える」を混ぜている（breakで抜ける形）。
//   whileは「捨てる」だけ、ifは「マッチする」だけ、と役割を1つずつにすると読みやすい
//   （ABC447 Cで学んだ「状態ごとに処理を分離する」と同じ考え方）
// ②bool ok は不要。最後に cnt >= k を見れば済む
//
//     int j = 0, cnt = 0;
//     for (int i = 0; i < n && cnt < k; i++) {
//         while (j < m && h.at(i) > b.at(j)) {
//             j++;                      // 小さすぎる体を捨てる
//         }
//         if (j < m) {                  // 使える体が残っていればマッチ
//             cnt++;
//             j++;
//         }
//     }
//     cout << (cnt >= k ? "Yes" : "No") << endl;
