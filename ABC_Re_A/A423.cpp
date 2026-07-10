#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, c;
    cin >> x >> c;

    int k = x / (1000 + c);

    cout << 1000 * k << endl;
}
