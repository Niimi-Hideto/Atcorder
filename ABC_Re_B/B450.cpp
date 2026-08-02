#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n + 1, vector<int>(n + 1));

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            cin >> vec.at(i).at(j);
        }
    }

    bool flag = false;
    for (int a = 1; a <= n - 2; a++) {
        for (int b = a + 1; b <= n - 1; b++) {
            for (int c = b + 1; c <= n; c++) {
                if (vec.at(a).at(c) > vec.at(a).at(b) + vec.at(b).at(c)) {
                    flag = true;
                }
            }
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}