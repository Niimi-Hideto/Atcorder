#include <bits/stdc++.h>
using namespace std;

// x が素数なら true、素数でなければ false を返す
// x が合成数なら x = a × b（2 ≤ a ≤ b）と分けられ、小さいほうの a は必ず √x 以下。
// だから √x 以下に割り切れる数がなければ素数と言える
bool is_prime(int x) {
    // i <= sqrt(x) だと double の誤差が心配なので、両辺を2乗して整数だけで比べる
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int q;
    cin >> q;

    vector<int> x(q);
    for (int i = 0; i < q; i++) {
        cin >> x.at(i);
    }

    // 1問あたり √X ≈ 550 回なので、全体で 10^4 × 550 ≈ 5.5×10^6 回
    for (int i = 0; i < q; i++) {
        cout << (is_prime(x.at(i)) ? "Yes" : "No") << endl;
    }
}

/* ===== 別解：エラトステネスのふるい =====
   最初に N 以下の全部について「素数かどうか」の表を作っておき、質問は表を見るだけ（1問 O(1)）。
   2 から順に、まだ消されていない数（＝素数）の倍数を全部消していき、残ったものが素数。
   - 外側は √N まででいい（N 以下の合成数は必ず √N 以下の約数を持つので、もう消えている）
   - i がもう消されている（合成数）なら、その倍数は i の約数の倍数としてもう消えているので飛ばす
   使い分け：同じ範囲の数について何度も聞かれ、上限が配列にできる大きさ（10^7 くらいまで）ならふるい。
             X が大きい（10^12 など）か、調べる数が少ないなら √X まで割る形

   const int N = 300000;
   vector<bool> deleted(N + 1, false);   // deleted[x] = true なら x は素数ではない
   for (int i = 2; i * i <= N; i++) {
       if (deleted.at(i)) continue;
       for (int j = i * 2; j <= N; j += i) {
           deleted.at(j) = true;
       }
   }
   cout << (deleted.at(x.at(i)) ? "No" : "Yes") << endl;
*/
