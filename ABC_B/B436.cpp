#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));


    int r = 0;
    int c = (n - 1) / 2;
    int k = 1;

    for (int i = 0; i < n * n; i++) {
        if (i == 0) {
            vec.at(0).at((n - 1) / 2) = 1;
        }
        else {
            if (vec.at((((r - 1) % n) + n) % n).at((c + 1) % n) == 0) {
                vec.at((((r - 1) % n) + n) % n).at((c + 1) % n) = k + 1;

                k += 1;
                r = ((((r - 1) % n) + n) % n);
                c = (c + 1) % n;
            }
            else {
                vec.at((r + 1) % n).at(c) = k + 1;
                k += 1;
                r = (r + 1) % n;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vec.at(i).at(j);
            if (j != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
