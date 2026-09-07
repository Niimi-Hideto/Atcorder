#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }

    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a.at(i);
    }

    vector<int> last(n + 1);
    for (int i = 1; i <= q; i++) {
        int tmp = a.at(i - 1);
        last.at(tmp) = i;
    }

    for (int x : p) {
        if (last.at(x) == 0) {
            cout << x << " ";
        }
    }
    for (int i = 1; i <= q; i++) {
        int tmp = a.at(i - 1);
        if (last.at(tmp) == i) {
            cout << tmp << " ";
        }
    }
    cout << endl;
}
