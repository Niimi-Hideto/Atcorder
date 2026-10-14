#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a.at(i).at(j);
        }
    }

    vector<int> row(n + 1);
    for (int i = 1; i <= n; i++) {
        row.at(i) = i;
    }

    int q;
    cin >> q;
    for (int test = 0; test < q; test++) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            swap(row.at(x), row.at(y));
        }
        else {
            cout << a.at(row.at(x)).at(y) << endl;
        }
    }
}
