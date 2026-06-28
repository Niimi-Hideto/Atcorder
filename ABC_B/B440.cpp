#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> time(n);
    vector<int> tmp(n);

    for (int i = 0; i < n; i++) {
        cin >> time.at(i);
        tmp.at(i) = time.at(i);
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (tmp.at(i) == time.at(j)) {
                cout << j + 1;
                if (i != 2) {
                    cout << " ";
                }
                break;
            }
        }
    }
    cout << endl;
}
