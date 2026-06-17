#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, b;
    cin >> h >> b;

    if (h < b) {
        cout << 0 << endl;
    }
    else {
        cout << h - b << endl;
    }
}

// 別解：max(0, h - b) で if/else 不要
// cout << max(0, h - b) << endl;
