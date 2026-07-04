#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        int index = i;
        while (index > 0) {
            tmp += index % 10;
            index = index / 10;
        }
        if (tmp == k) {
            ans++;
        }
    }
    cout << ans << endl;
}
