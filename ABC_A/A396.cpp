#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    for (int i = 0; i < n - 2; i++) {
        if (vec.at(i) == vec.at(i + 1) && vec.at(i + 1) == vec.at(i + 2) && vec.at(i + 2) == vec.at(i)) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

// a==b && b==c なら a==c は自動的に成り立つので最後の条件は不要
// if (vec.at(i) == vec.at(i + 1) && vec.at(i + 1) == vec.at(i + 2)) {
