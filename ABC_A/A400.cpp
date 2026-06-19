#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    int b;

    if ((400 % a) == 0) {
        b = 400 / a;
        cout << b << endl;
    }
    else {
        cout << -1 << endl;
    }
}
