#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if ((x + y) <= 12) {
        cout << x + y << endl;
    }
    else if (x == 12 && y == 12) {
        cout << x << endl;
    }
    else {
        cout << (x + y) % 12 << endl;
    }
}

// 別解：(x + y - 1) % 12 + 1 で if/else 不要
// cout << (x + y - 1) % 12 + 1 << endl;
