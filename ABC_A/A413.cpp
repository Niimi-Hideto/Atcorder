#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int p;
    int sum = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> p;
        sum += p;
    }
    if (sum <= m) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
