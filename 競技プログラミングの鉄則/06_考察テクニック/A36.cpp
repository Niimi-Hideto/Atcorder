#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << (2 * n - 2 <= k && (k - (2 * n - 2)) % 2 == 0 ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. 2 * n − 2（最短の移動回数）が 2 回出てくるので名前を付けると、「最短以上で、余りが偶数」とそのまま読める

   int d = 2 * (n - 1);  // 最短の移動回数
   cout << (d <= k && (k - d) % 2 == 0 ? "Yes" : "No") << endl;
*/
