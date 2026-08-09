#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 0;
    while (i < n) {
        i++;

        if (i % 3 == 0) {
            cout << "Fizz" << endl;
        }
        else {
            cout << i << endl;
        }
    }
}

// 改善点: 繰り返し回数が決まっているときはwhileよりforが素直
// for (int i = 1; i <= n; i++) {
//     if (i % 3 == 0) {
//         cout << "Fizz" << endl;
//     }
//     else {
//         cout << i << endl;
//     }
// }
