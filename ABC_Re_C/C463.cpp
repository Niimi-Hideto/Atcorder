#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n), l(n);
    for (int i = 0; i < n; i++) {
        cin >> h.at(i) >> l.at(i);
    }

    vector<int> suf_max(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suf_max.at(i) = max(h.at(i), suf_max.at(i + 1));
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        int k = upper_bound(l.begin(), l.end(), t) - l.begin();
        cout << suf_max.at(k) << endl;
    }
}
