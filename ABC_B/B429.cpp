#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> num(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> num.at(i);
        sum += num.at(i);
    }

    int tmp = sum - m;
    if (count(num.begin(), num.end(), tmp) >= 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
