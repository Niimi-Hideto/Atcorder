#include <bits/stdc++.h>
using namespace std;

bool check(double mid, int n) {
    if (mid * (mid * mid + 1) < n) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    int n;
    cin >> n;

    double left = 1.0, right = 100000;
    double mid;
    while (left + 0.001 < right) {
        mid = (left + right) / 2.0;
        bool answer = check(mid, n);
        if (answer == false) {
            left = mid + 0.001;
        }
        else {
            right = mid;
        }
    }

    cout << fixed << setprecision(6) << mid << endl;
}

/* ===== 改善点 =====
   1. left = 1.0 だと N = 1 の答え（約 0.682）を取りこぼす。x > 0 なので left = 0 から
   2. 実数には「次の数」がないので、left = mid + 0.001 の +0.001 は不要（間の答えを飛ばす）。
      left = mid / right = mid でどちらも mid をそのまま使う
   3. ループを抜けたあとの mid は最後に計算した真ん中で、最終的な範囲とずれている。left を出力する
   4. 実数は left == right にならないので、回数を決めて回す（100回で十分な精度）
   5. 判定関数は1行で書ける

   bool check(double x, int n) {
       return x * x * x + x >= n;
   }

   double left = 0, right = 100000;
   for (int i = 0; i < 100; i++) {
       double mid = (left + right) / 2;
       if (check(mid, n)) right = mid;
       else left = mid;
   }
   cout << fixed << setprecision(6) << left << endl;
*/
