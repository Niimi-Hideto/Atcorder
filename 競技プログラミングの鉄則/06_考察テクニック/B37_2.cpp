#include <bits/stdc++.h>
using namespace std;

// int main() {
//     long long n;
//     cin >> n;
//
//     vector<int> presum(10 + 1);
//     for (int i = 1; i <= 10; i++) {
//         presum.at(i) = presum.at(i - 1) + i;
//     }
//
//     long long ans = 0, p = 1;
//     while (n / p > 0) {
//         if (n / (p * 10) > 0) {
//             ans += (n / p * 10) * (presum.at(10) * p);
//         }
//         if (n % (p * 10) != 0) {
//             ans += presum.at(n % (p * 10)) * p;
//         }
//
//         p *= 10;
//     }
//     cout << ans << endl;
// }

int main() {
    long long n;
    cin >> n;

    long long cnt = n + 1;
    long long ans = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long full = cnt / (p * 10);
        ans += full * 45 * p;

        long long rest = cnt % (p * 10);
        long long d = rest / p;
        ans += d * (d - 1) / 2 * p;
        ans += d * (rest % p);
    }
    cout << ans << endl;
}
