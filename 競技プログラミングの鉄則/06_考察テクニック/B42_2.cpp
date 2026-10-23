#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    long long ans = 0;
    vector<int> da = { 1, 1, -1, -1 };
    vector<int> db = { 1, -1, 1, -1 };
    for (int type = 0; type < 4; type++) {

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            long long tmp = 0;
            if (da.at(type) > 0) {
                tmp += a.at(i);
            }
            else {
                tmp -= a.at(i);
            }
            if (db.at(type) > 0) {
                tmp += b.at(i);
            }
            else {
                tmp -= b.at(i);
            }

            if (tmp > 0) {
                sum += tmp;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. da・db は +1 か -1 なので、if で足すか引くかを分けず、掛け算で符号を付ければ 1 行で済む（20–32 行目）。
      ただし da・db が int のままだと、da × a + db × b を int のまま計算してから long long に入れるので、
      合計 2×10^9 で int を超える。da・db を long long にして、掛け算の時点で long long にする（14・15 行目）

    vector<long long> da = { 1, 1, -1, -1 };           // 14 行目
    vector<long long> db = { 1, -1, 1, -1 };           // 15 行目

            long long tmp = da.at(type) * a.at(i) + db.at(type) * b.at(i);   // 20–32 行目
*/
