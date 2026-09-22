#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    long long l;
    cin >> n >> s >> l;

    vector<long long> a(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a.at(i);
    }
    vector<long long> pre_a(n + 1);
    for (int i = 1; i < n; i++) {
        pre_a.at(i) = pre_a.at(i - 1) + a.at(i);
    }

    int cnt = 0;
    for (int i = s - 1; i < n; i++) {
        for (int j = s - 1; j >= 0; j--) {
            long long tmp =
                min((pre_a.at(i) - pre_a.at(s - 1)) * 2 + pre_a.at(s - 1) - pre_a.at(j),
                    (pre_a.at(i) - pre_a.at(s - 1)) + (pre_a.at(s - 1) - pre_a.at(j)) * 2);

            if (tmp > l) {
                break;
            }
            cnt = max(cnt, i - j);
        }
    }

    cout << cnt + 1 << endl;
}

/* ===== 改善点 =====
   1. road は使っていないので消す
   2. pre_a.at(k) が「街 k+1 の座標」になっていて、s-1 や cnt+1 など ±1 があちこちに出る。
      pre.at(i) = 街 i の座標（街1 が 0）にすると、添字と街の番号が一致する
   3. 同じ引き算を何度も書いているので、左右の距離を変数にする
      （左端の街を l にすると入力の L と被るので lt / rt にする）

   vector<long long> pre(n + 1);   // pre.at(i) = 街 i の座標、pre.at(1) = 0
   for (int i = 2; i <= n; i++) {
       pre.at(i) = pre.at(i - 1) + a.at(i - 1);
   }

   for (int rt = s; rt <= n; rt++) {         // 右端の街
       for (int lt = s; lt >= 1; lt--) {     // 左端の街
           long long dr = pre.at(rt) - pre.at(s);   // 右端までの距離
           long long dl = pre.at(s) - pre.at(lt);   // 左端までの距離
           long long cost = min(2 * dr + dl, dr + 2 * dl);
           if (cost > l) {
               break;
           }
           cnt = max(cnt, rt - lt + 1);      // 訪れる街の数そのもの
       }
   }
   cout << cnt << endl;
*/
