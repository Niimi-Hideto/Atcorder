#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    for (int i = 0; i < q; i++) {
        int rc;
        int num;

        cin >> rc >> num;

        if (rc == 1) {
            cout << num * w << endl;
            h -= num;
        }
        else {
            cout << num * h << endl;
            w -= num;
        }
    }
}
