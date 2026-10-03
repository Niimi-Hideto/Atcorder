#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<int> c = a;
    sort(c.begin(), c.end());
    int num = -1;
    for (int i = 1; i <= n; i++) {
        if (a.at(i) != c.at(i) && num == -1) {
            num = i;
        }
        if (num == -1 && i == n - k + 1) {
            num = n - k + 1;
        }
    }

    if (num == -1) {
        cout << "Yes" << endl;
        return 0;
    }

    bool ok = true;
    for (int i = num + k; i <= n; i++) {
        if (a.at(i) != c.at(i)) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. K < N なので n - k + 1 は 2〜n のどこかで、21行目で num は必ず入る。
      26〜29行目の num == -1 の分岐は一度も通らないので消せる
   2. ずれている位置の「最初 l」と「最後 r」を求めれば、「ずれている位置を全部、長さ K の範囲1つで
      覆えるか」＝ r - l + 1 <= k だけで判定できる。範囲の始まりを決める工夫も、後ろを確かめるループも要らない
   3. sort が使っていない a.at(0)（中身は0）まで並べている。A ≥ 1 なので今は壊れないが、
      使う範囲だけ並べる方が安全

   sort(c.begin() + 1, c.end());
   int l = -1, r = -1;
   for (int i = 1; i <= n; i++) {
       if (a.at(i) != c.at(i)) {
           if (l == -1) l = i;
           r = i;
       }
   }
   cout << (l == -1 || r - l + 1 <= k ? "Yes" : "No") << endl;
*/
