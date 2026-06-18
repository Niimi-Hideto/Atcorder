#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            ans += i * i * i;
        }
        else {
            ans -= i * i * i;
        }
    }
    cout << ans << endl;
}
