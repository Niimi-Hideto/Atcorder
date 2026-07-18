#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long R = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));

        if ((x1 + r1 <= x2) || ((y1 + r1 <= y2))) {
            long long R = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
            if (R <= ((r1 * r1) + (2 * r1 * r2) + (r2 * r2))) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            if (R >= ((r1 * r1) - (2 * r1 * r2) + (r2 * r2))) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}

/*
int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        long long lo = (r1 - r2) * (r1 - r2);
        long long hi = (r1 + r2) * (r1 + r2);

        if (lo <= d2 && d2 <= hi) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
*/
