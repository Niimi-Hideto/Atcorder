#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (cnt.count(a) == 0) {
            cnt[a]++;
        }
        else {
            ans += cnt.at(a);
            cnt.at(a)++;
        }
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. map の [] は、まだないキーなら 0 から始まるので、初めて出てきた値でも ans に 0 を足すだけで済む。
      出てきたかどうかの if の場合分けはいらない（14–20 行目、A54 と同じ）

        ans += cnt[a];                                 // 14–20 行目
        cnt[a]++;
*/
