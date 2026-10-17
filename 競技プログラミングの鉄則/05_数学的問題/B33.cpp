#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, w;
    cin >> n >> h >> w;

    long long x = 0;
    for (int i = 1; i <= n; i++) {
        long long a, b;
        cin >> a >> b;

        x ^= (a - 1);
        x ^= (b - 1);
    }
    cout << (x != 0 ? "First" : "Second") << endl;
}
