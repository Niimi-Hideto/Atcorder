#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    bool ok = false;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a.at(i) + a.at(j) + a.at(k) == 1000) {
                    ok = true;
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
