#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> c(n - 1, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            cin >> c.at(i).at(j);
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i; j < n - 2; j++) {
            for (int k = i + 1; j < n - 1; j++) {
            }
        }
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> cost(n, vector<long long>(n, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> cost.at(i).at(j);
        }
    }

    bool found = false;
    for (int a = 0; a < n - 2; a++) {
        for (int b = a + 1; b < n - 1; b++) {
            for (int c = b + 1; c < n; c++) {
                if (cost.at(a).at(b) + cost.at(b).at(c) < cost.at(a).at(c)) {
                    found = true;
                }
            }
        }
    }

    cout << (found ? "Yes" : "No") << endl;
}
*/
