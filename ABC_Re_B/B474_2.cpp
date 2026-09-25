#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p.at(i);
    }

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int tmp = (i + 9) / 10;
        if (p.at(i) > tmp * 10) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. i 番目の人の判定に他の人の情報は要らないので、vector に溜めず読みながら判定できる
   2. tmp の中身はグループ番号なので g にする

   for (int i = 1; i <= n; i++) {
       int p;
       cin >> p;
       int g = (i + 9) / 10;
       if (p > g * 10) {
*/
