#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a.at(i) * b.at(i));
    }

    cout << ans << endl;
}
