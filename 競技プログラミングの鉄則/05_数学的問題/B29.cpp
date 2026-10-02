#include <bits/stdc++.h>
using namespace std;

int power(long long a, long long b, long long m) {
    long long p = a;
    long long ans = 1;
    for (int i = 0; i < 60; i++) {
        long long wari = (1LL << i);
        if ((b / wari) % 2 == 1) {
            ans *= p;
            if (ans / m > 0) {
                ans %= m;
            }
        }
        p = (p * p) % m;
    }
    return ans;
}


int main() {
    long long a, b;
    cin >> a >> b;

    cout << power(a, b, 1000000007) << endl;
}

/* ===== 改善点 =====
   1. ans が m より小さいとき ans % m は ans のまま変わらないので、「m 以上のときだけ割る」if は要らない。
      % は必要なときだけではなく、毎回そのまま書いてよい（15行目と同じ形にそろう）
   2. 中は全部 long long で計算しているので、戻り値も long long にそろえる

   long long power(long long a, long long b, long long m) {
   ans = (ans * p) % m;
*/
