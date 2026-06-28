#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    cout << -1 << endl;
    bool flag = true;

    for (int i = 1; i < n; i++) {
        flag = true;
        for (int j = i - 1; j >= 0; j--) {
            if (vec.at(i) < vec.at(j)) {
                cout << j + 1 << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << -1 << endl;
        }
    }
}
