#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<long long> vertex(l);
    int pos = 0;
    vertex.at(0)++;
    for (int i = 0; i < n - 1; i++) {
        int d;
        cin >> d;

        pos = (pos + d) % l;
        vertex.at(pos)++;
    }

    long long ans = 0;
    if (l % 3 == 0) {
        for (int i = 0; i < (l / 3); i++) {
            ans += vertex.at(i) * vertex.at(i + l / 3) * vertex.at(i + (l / 3) * 2);
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }

}

/* ===== 改善点 =====
   1. L が 3 で割り切れないとき ans は 0 のままなので、cout は if の外に 1 回だけでいい。else ごと要らない（20–28 行目）

    long long ans = 0;
    if (l % 3 == 0) {
        for (…) { … }
    }
    cout << ans << endl;

   2. 中身は「その位置にある点の個数」なので名前は cnt に。l / 3 は何度も使うので名前を付ける（8・22 行目）

    vector<long long> cnt(l);
    int k = l / 3;
        ans += cnt.at(i) * cnt.at(i + k) * cnt.at(i + k * 2);
*/
