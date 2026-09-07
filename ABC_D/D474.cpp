#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (a.at(i) > b.at(i)) {
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;
    }
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            if (a.at(i) > b.at(i)) {
                cout << 1000000000000000000LL - a.at(i) << " ";
            }
            else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
}
