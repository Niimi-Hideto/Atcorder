#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    int ans = 1;
    int now;
    cin >> now;
    int time = now;

    for (int i = 1; i < n; i++) {
        cin >> now;
        if (now - time >= c) {
            ans++;
            time = now;
        }
    }
    cout << ans << endl;
}
