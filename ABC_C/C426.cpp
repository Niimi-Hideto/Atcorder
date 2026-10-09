#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> os(n + 1);
    for (int i = 1; i <= n; i++) {
        os.at(i)++;
    }

    int maxx = 1;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        if (maxx > x) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        while (maxx <= x) {
            ans += os.at(maxx);
            os.at(y) += os.at(maxx);
            maxx++;
        }
        cout << ans << endl;
    }
}

/* ===== 改善点 =====
   1. maxx > x のときは while が 1 回も回らず ans = 0 のまま出力されるので、18〜21 行目の if は要らない
   2. maxx は「まだ PC が残っているかもしれない一番古いバージョン」なので low などの名前にする
   3. 移したあとの os.at(low) を 0 にしておくと、「os.at(v) ＝ バージョン v の台数」がいつでも正しいままになる
   4. 各バージョンに 1 台ずつなので、10 行目は = 1 と書くと意味が読める

   os.at(i) = 1;                    // 10 行目
   int low = 1;                     // 13 行目
   while (low <= x) {               // 24〜28 行目
       ans += os.at(low);
       os.at(y) += os.at(low);
       os.at(low) = 0;
       low++;
   }
*/
