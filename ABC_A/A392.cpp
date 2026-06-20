#include <bits/stdc++.h>
using namespace std;

int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    bool flag = false;

    if (a1 * a2 == a3) {
        flag = true;
    }
    else if (a2 * a3 == a1) {
        flag = true;
    }
    else if (a3 * a1 == a2) {
        flag = true;
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
