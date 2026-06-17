#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, x, y;
    cin >> p >> q >> x >> y;
    if (p <= x && x <= p + 99 && q <= y && y <= q + 99) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
