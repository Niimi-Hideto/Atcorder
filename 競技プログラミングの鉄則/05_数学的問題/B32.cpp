#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (a.at(j) <= i && dp.at(i - a.at(j)) == false) {
                dp.at(i) = true;
                break;
            }
        }
    }

    cout << (dp.at(n) ? "First" : "Second") << endl;
}

/* ===== 改善点 =====
   1. 手は K 通り全部調べているので、並べる順番は結果に関係ない。12 行目の sort は消してよい
   2. a は添字 0 のダミーが要らないので、サイズ k で 0〜k−1 に入れる

   vector<int> a(k);
   for (int i = 0; i < k; i++) {
   for (int j = 0; j < k; j++) {
*/
