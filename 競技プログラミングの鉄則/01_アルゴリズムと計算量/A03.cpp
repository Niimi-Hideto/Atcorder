#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> q.at(i);
    }

    bool ok = false;
    for (int i = 0; i < n && !ok; i++) {
        for (int j = 0; j < n; j++) {
            if (p.at(i) + q.at(j) == k) {
                ok = true;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}
