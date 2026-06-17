#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    cout << x * pow(2, y) << endl;
}

/*
// 別解：ビットシフト（整数のまま2のY乗を計算）
// cout << x * (1 << y) << endl;
*/
