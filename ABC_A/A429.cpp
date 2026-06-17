#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        if (i + 1 <= m) {
            cout << "OK" << endl;
        }
        else {
            cout << "Too Many Requests" << endl;
        }
    }
}

/*
// 別解：i を1始まりにすると i+1 が不要
// for (int i = 1; i <= n; i++) {
//     if (i <= m) cout << "OK" << endl;
//     else cout << "Too Many Requests" << endl;
// }
*/
