#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp = 0;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        if (a <= tmp) {
            flag = false;
            break;
        }
        tmp = a;
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
