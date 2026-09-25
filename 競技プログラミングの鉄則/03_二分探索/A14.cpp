#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) cin >> b.at(i);
    for (int i = 0; i < n; i++) cin >> c.at(i);
    for (int i = 0; i < n; i++) cin >> d.at(i);

    // 4つ全部試すと N^4 = 10^12 で間に合わないので、2つずつに分ける（半分全列挙）
    // p = A と B から1枚ずつ取った合計の全通り、q = C と D の全通り（それぞれ N^2 = 10^6 個）
    // 合計の最大は 2×10^8 なので int に収まる
    vector<int> p, q;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            p.push_back(a.at(x) + b.at(y));
        }
    }
    for (int z = 0; z < n; z++) {
        for (int w = 0; w < n; w++) {
            q.push_back(c.at(z) + d.at(w));
        }
    }

    // p の値を1つ決めると、q に必要なのは K - p ちょうど。q をソートして二分探索で探す
    sort(q.begin(), q.end());
    for (int i = 0; i < (int)p.size(); i++) {
        if (binary_search(q.begin(), q.end(), k - p.at(i))) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

/* ===== lower_bound で書く場合（本の解答の形）=====
   lower_bound は「以上の最初の位置」を返すので、値がなくても位置が返る。
   範囲の外でないか → 値がちょうど一致するか、の順に確認する

   auto it = lower_bound(q.begin(), q.end(), k - p.at(i));
   if (it != q.end() && *it == k - p.at(i)) {
*/
