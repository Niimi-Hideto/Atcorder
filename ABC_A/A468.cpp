#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int ans = 0;
    if (a1 < a2 && a2 > a3) {
        ans++;
    }

    for (int i = 0; i < n - 3; i++) {
        a1 = a2;
        a2 = a3;
        cin >> a3;

        if (a1 < a2 && a2 > a3) {
            ans++;
        }
    }

    cout << ans << endl;
}
