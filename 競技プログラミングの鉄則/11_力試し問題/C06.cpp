#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        if (i != n) {
            cout << i << " " << i + 1 << endl;
        }
        else {
            cout << i << " " << 1 << endl;
        }
    }
}
