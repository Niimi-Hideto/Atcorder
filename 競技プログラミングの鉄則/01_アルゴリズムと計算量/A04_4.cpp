#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 9; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}
