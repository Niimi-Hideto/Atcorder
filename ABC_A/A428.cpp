#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;

    int loop;
    int remainder;
    int ans;

    loop = x / (a + b);
    remainder = x % (a + b);

    ans = loop * a * s;

    if (remainder <= a) {
        ans += remainder * s;
    }
    else {
        ans += a * s;
    }

    cout << ans << endl;
}

// 別解：min を使うと if/else 不要
// ans += min(remainder, a) * s;




