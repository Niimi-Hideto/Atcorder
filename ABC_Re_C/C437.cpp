#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;

        // cost.at(i) = トナカイiを「ソリに乗せる値段」= W_i + P_i
        //   乗せると引く側から P_i が抜け、乗る側に W_i が加わるので、
        //   どちらも同じ方向に効いて合計 W_i + P_i を消費する。
        // p_sum = 全員のPの合計 = 予算 SP
        vector<long long> cost(n);
        long long p_sum = 0;

        for (int i = 0; i < n; i++) {
            long long w, p;
            cin >> w >> p;
            cost.at(i) = w + p;
            p_sum += p;
        }

        // 予算内で個数を最大化するので、安い順に買う
        sort(cost.begin(), cost.end());

        // 合計は最大 3×10^5 × 2×10^9 = 6×10^14 なので long long
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += cost.at(i);
            if (sum > p_sum) {
                break;
            }
            ans++;
        }

        cout << ans << endl;
    }
}
