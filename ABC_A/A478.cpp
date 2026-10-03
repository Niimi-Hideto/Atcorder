#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int tmp = m % n;
    for (int i = 1; i <= n; i++) {
        int amari = 0;
        if (tmp >= i) {
            amari = 1;
        }
        cout << (m / n) + amari << endl;
    }
}

/* ===== 改善点 =====
   1. amari は余りではなく「+1粒するかどうか（0か1）」なので、名前を extra などにする
      （本当の余りは tmp = m % n のほう）
   2. 比較の結果（true / false）は足し算で 1 / 0 になるので、if で 0/1 を入れなくても1行で書ける

   cout << (m / n) + (i <= tmp) << endl;
*/
