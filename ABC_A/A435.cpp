#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (i + 1);
    }

    cout << ans << endl;
}

// 別解：ガウスの公式 1+2+...+N = N*(N+1)/2
// cout << n * (n + 1) / 2 << endl;
