#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int diff = k - (i + j);
            if (diff <= n && diff > 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. diff の中身は「白のカードに書く数」なので、white や c にすると意味がそのまま読める
   2. 範囲チェックは小さいほうから書くと「1 ≤ c ≤ N」と同じ並びになり、範囲だと一目で分かる

   int c = k - (i + j);
   if (1 <= c && c <= n) {
*/
