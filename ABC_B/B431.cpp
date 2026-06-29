#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    vector<vector<int>> weight(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> weight.at(i).at(0);
        weight.at(i).at(1) = 0;
    }

    int q;
    cin >> q;

    int tmp;
    for (int i = 0; i < q; i++) {
        cin >> tmp;
        tmp--;
        if (weight.at(tmp).at(1) == 0) {
            x += weight.at(tmp).at(0);
            weight.at(tmp).at(1) = 1;
            cout << x << endl;
        }
        else {
            x -= weight.at(tmp).at(0);
            weight.at(tmp).at(1) = 0;
            cout << x << endl;
        }
    }
}
