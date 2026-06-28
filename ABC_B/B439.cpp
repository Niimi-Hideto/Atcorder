#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec;
    vector<int> tmp(4);
    bool flag = true;

    while (flag) {
        for (int i = 0; i < 4; i++) {
            tmp.at(i) = n % 10;
            n = n / 10;
        }
        n = (tmp.at(0) * tmp.at(0)) + (tmp.at(1) * tmp.at(1))
            + (tmp.at(2) * tmp.at(2)) + (tmp.at(3) * tmp.at(3));

        if (n == 1) {
            break;
        }
        if (count(vec.begin(), vec.end(), n) == 0) {
            vec.push_back(n);
        }
        else if (count(vec.begin(), vec.end(), n) == 1) {
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
