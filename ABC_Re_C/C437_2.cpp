#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        int n;
        cin >> n;


        vector<long long> wp(n + 1);
        long long sw = 0;
        for (int i = 1; i <= n; i++) {
            int w, p;
            cin >> w >> p;

            wp.at(i) = w + p;
            sw += w;
        }

        sort(wp.rbegin(), wp.rend());
        vector<long long> sum_wp(n + 1);
        for (int i = 1; i <= n; i++) {
            sum_wp.at(i) += sum_wp.at(i - 1) + wp.at(i - 1);
        }

        int cnt = lower_bound(sum_wp.begin(), sum_wp.end(), sw) - sum_wp.begin();
        cout << n - cnt << endl;
    }
}

/* ===== 改善点 =====
   1. wp は添字 0 のダミーが要らないので、サイズ n で 0〜n−1 に入れる（降順にしたとき 0 が末尾に行くことを気にしなくてよくなる）
   2. sum_wp.at(i) はまだ 0 なので、+= ではなく = で書く
   3. 外側と内側のループ変数が両方 i で、内側が外側を隠している。外側はテストケースの番号なので t にする

   for (int t = 0; t < test; t++) {
       vector<long long> wp(n);
       for (int i = 0; i < n; i++) {
           wp.at(i) = w + p;
       sum_wp.at(i) = sum_wp.at(i - 1) + wp.at(i - 1);
*/
