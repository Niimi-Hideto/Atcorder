#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    if (w * (100 * 100) < 25 * (h * h)) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
