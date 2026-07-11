#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool flag = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 0) {
            flag = false;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}
