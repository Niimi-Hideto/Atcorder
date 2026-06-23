#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);

    bool dif = true;

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n - 1; i++) {
        if (vec.at(i) == vec.at(i + 1)) {
            dif = false;
            break;
        }
    }
    if (dif) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    bool all = true;
    for (int i = 1; i < m + 1; i++) {
        if (count(vec.begin(), vec.end(), i) == 0) {
            all = false;
            break;
        }
    }
    if (all) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
