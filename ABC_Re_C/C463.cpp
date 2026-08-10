#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    vector<int> l(n);

    for (int i = 0; i < n; i++) {
        cin >> h.at(i) >> l.at(i);
    }

    vector<int> max_high(n);
    max_high.at(n - 1) = h.at(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        max_high.at(i) = max(max_high.at(i + 1), h.at(i));
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        int idx = (upper_bound(l.begin(), l.end(), t) - l.begin());
        cout << max_high.at(idx) << endl;
    }
}
