#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 0; j < n; j++) {
            if (i <= a.at(j)) {
                num++;
            }
        }
        if (i <= num) {
            ans = max(ans, i);
        }
    }

    cout << ans << endl;
}
