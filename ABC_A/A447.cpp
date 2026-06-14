#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (2 * (m - 1) + 1 <= n) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

/*
// 別解：最大人数から考える
// N席に座れる最大人数は (N+1)/2（整数除算）
int main() {
    int n, m;
    cin >> n >> m;

    if (m <= (n + 1) / 2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
*/
