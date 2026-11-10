#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<int> ans(n + 1);
    for (int i = n; i >= 2; i--) {
        ans.at(a.at(i)) += ans.at(i) + 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans.at(i);
        if (i != n) {
            cout << " ";
        }
    }
    cout << endl;
}
