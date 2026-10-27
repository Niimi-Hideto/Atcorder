#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x ^= a;
    }

    cout << (x != 0 ? "First" : "Second") << endl;
}
