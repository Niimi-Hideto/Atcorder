#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n) {
            if (a.at(j) * 2 >= b.at(i)) {
                ans++;
                j++;
                break;
            }
            j++;
        }
    }
    cout << ans << endl;
}
