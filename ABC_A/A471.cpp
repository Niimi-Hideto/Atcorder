#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    double b;
    cin >> a >> b;

    int add = a + b;
    int minus = a - b;
    double waru = a / b;
    int seki = a * b;

    if (add == 9 || minus == 9 || waru == 9 || seki == 9) {
        cout << "Nine" << endl;
    }
    else {
        cout << "Nein" << endl;
    }
}

// 改善点: 変数名を英語で統一 + 割り算はa==9*bの整数比較に置き換える
// int sum = a + b;
// int diff = a - b;
// int product = a * b;
//
// if (sum == 9 || diff == 9 || a == 9 * b || product == 9) {
//     cout << "Nine" << endl;
// }
// else {
//     cout << "Nein" << endl;
// }
