#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    const long long m = 1000000007;
    long long p = a, ans = 1;
    // for (int i = 0; i <= a; i++) {
    for (int i = 0; i < 30; i++) {
        if ((b >> i) & 1) {
            ans = ans * p % m;
        }
        p = p * p % m;
    }

    cout << ans << endl;
}
