#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    bool ok = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == x) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
