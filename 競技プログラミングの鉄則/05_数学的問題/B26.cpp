#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool>  prime(n + 1);
    for (int i = 2; i * i <= n; i++) {
        if (prime.at(i) == true) continue;
        for (int j = i * 2; j <= n; j += i) {
            prime.at(j) = true;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!prime.at(i)) {
            cout << i << endl;
        }
    }
}

/* ===== 改善点 =====
   prime という名前なのに true が「素数ではない」を表していて、出力の !prime.at(i) で混乱しやすい。
   中身を名前に合わせて、最初は全部 true（素数）にして倍数を false にすると、出力がそのまま読める

   vector<bool> is_prime(n + 1, true);
   if (!is_prime.at(i)) continue;
   is_prime.at(j) = false;
   if (is_prime.at(i)) {
*/
