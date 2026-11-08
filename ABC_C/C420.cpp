#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1), b(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b.at(i);
    }
    for (int i = 1; i <= n; i++) {
        sum += min(a.at(i), b.at(i));
    }

    for (int query = 1; query <= q; query++) {
        char c;
        int x, v;
        cin >> c >> x >> v;

        sum -= min(a.at(x), b.at(x));
        if (c == 'A') {
            a.at(x) = v;
        }
        else {
            b.at(x) = v;
        }
        sum += min(a.at(x), b.at(x));

        cout << sum << endl;
    }
}
