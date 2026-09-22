#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1 << 9; i >= 1; i /= 2) {
        cout << n / i;
        n %= i;
    }
    cout << endl;
}
