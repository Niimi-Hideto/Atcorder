#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    if (a.at(k - 1) == 9) {
        cout << a.at(0) << endl;
    }
    else {
        cout << -1 << endl;
    }
}
