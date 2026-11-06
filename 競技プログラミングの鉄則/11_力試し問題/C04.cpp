#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    /* 自分で書いたもの（√N まで回すところまでは直せていたが、ペアの大きいほう n / i を出していない。
       また i が int なので、i * i が int の上限を超えて壊れる）
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }
    cout << n << endl;
    */

    // 約数は「i と n / i」のペアになっていて、小さいほう i は必ず √N 以下。
    // なので i を √N まで回し、割り切れたらペアの両方を集める。√(10^13) ≈ 3.2×10^6 回で済む
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {  // i * i <= n ＝ i <= √N（i * i は 10^13 くらいなので long long）
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);  // ペアの大きいほう。N が平方数で i = √N のときは同じ数なので 1 回だけ
            }
        }
    }

    // 小さいほうと大きいほうが交互に入っているので、小さい順に並べ直す
    sort(divisors.begin(), divisors.end());
    for (long long x : divisors) {
        cout << x << endl;
    }
}
