#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        if ((r2 * r2) - (2 * r2 * r1) + (r1 * r1) <= d
            && d <= (r2 * r2) + (2 * r2 * r1) + (r1 * r1)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}
