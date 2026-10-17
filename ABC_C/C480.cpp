#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    int ans = 0;
    if (a.at(1) != 0) {
        ans++;
    }
    int latest = k;

    for (int i = 1; i <= n; i++) {
        if (a.at(i) > t) break;
        int diff = a.at(i) - latest;
        if (diff == 0) {
            latest = a.at(i) + k;
            continue;
        }

        if (diff > 0) {
            ans += diff / k;
        }
        if (diff > 0 && diff % k) {
            ans++;
        }

        latest = a.at(i) + k;
    }

    int diff = t - latest;
    if (diff > 0) {
        ans += diff / k;
    }
    if (diff > 0 && diff % k) {
        ans++;
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. 23〜26行目の diff == 0 の特別扱いは要らない。diff が0なら下の diff > 0 の if に入らず、
      35行目で latest = a.at(i) + k になるので結果は同じ
   2. 切り上げは2つの if に分けず (diff + k - 1) / k の1行で書ける（diff + k - 1 は最大約2×10^9 で int に収まる）
   3. 同じ計算をループの中（28〜33行目）と最後（39〜44行目）の2か所に書いていて、
      WA は片方（42行目）だけ diff > 0 && を直し忘れたのが原因。1行にしておけば見比べやすく、片方だけずれにくい

   // ループの中（28〜33行目）も最後（39〜44行目）もこの形
   if (diff > 0) {
       ans += (diff + k - 1) / k;
   }
*/

/* ===== 別解：座標圧縮＋いもす法（解説の2つ目の方法）=====
   お湯が出始める A_i・止まる A_i + K に 0 と T を足して座標圧縮し、隣り合う時刻の間を1つの区間にする。
   いもす法で「その区間でお湯を出している青木君の数」を出し、0 の区間（長さ d）だけ (d + K − 1) / K 回押す。
   T より後の時刻は最初から入れないので、「T より後の青木君」「最後の部分」の場合分けが消える。
   A_i + K は最大 2×10^9 で int を超えるので long long

   vector<long long> xs = {0, t};
   for (int i = 0; i < n; i++) {
       if (a.at(i) <= t) xs.push_back(a.at(i));
       if (a.at(i) + k <= t) xs.push_back(a.at(i) + k);
   }
   sort(xs.begin(), xs.end());
   xs.erase(unique(xs.begin(), xs.end()), xs.end());   // 座標圧縮（鉄則 A15）

   int m = xs.size();
   vector<int> imos(m + 1);
   for (int i = 0; i < n; i++) {
       if (a.at(i) > t) continue;
       imos.at(lower_bound(xs.begin(), xs.end(), a.at(i)) - xs.begin())++;
       if (a.at(i) + k <= t) {
           imos.at(lower_bound(xs.begin(), xs.end(), a.at(i) + k) - xs.begin())--;
       }
   }

   for (int j = 1; j < m; j++) imos.at(j) += imos.at(j - 1);

   long long ans = 0;
   for (int j = 0; j + 1 < m; j++) {
       if (imos.at(j) == 0) {                         // xs[j]〜xs[j+1] は青木君だけではお湯が出ない
           long long d = xs.at(j + 1) - xs.at(j);
           ans += (d + k - 1) / k;
       }
   }

   典型手法は、問題を解くためだけでなく、場合分けを減らして実装ミスを防ぐ道具にもなる
*/