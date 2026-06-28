#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> color(n, vector<int>(4));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (j < 3) {
                cin >> color.at(i).at(j);
            }
            else {
                color.at(i).at(3) = 0;
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans.at(i) = color.at(i).at(0);
    }

    for (int i = 0; i < m; i++) {
        int count = 1;

        for (int k = 0; k < n; k++) {
            if (color.at(k).at(1) - 1 == i) {
                color.at(k).at(0) = color.at(k).at(2);
                color.at(i).at(3) += 1;
                ans.at(k) = color.at(k).at(2);
            }
        }

        vector<int> tmp(n);
        for (int q = 0; q < n; q++) {
            tmp.at(q) = ans.at(q);
        }

        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < n - 1; j++) {
            if (tmp.at(j) != tmp.at(j + 1)) {
                count++;
            }
        }
        cout << count << endl;
    }
}
