#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> old(n);
    vector<int> next(n);

    for (int i = 0; i < n; i++) {
        cin >> old.at(i);
        cin >> next.at(i);
    }

    for (int i = 1; i < m + 1; i++) {
        cout << count(next.begin(), next.end(), i)
            - count(old.begin(), old.end(), i) << endl;
    }
}
