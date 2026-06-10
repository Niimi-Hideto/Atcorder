#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> number(n);
    for (int i = 0; i < n; i++) {
        cin >> number.at(i);
    }
    int x;
    cin >> x;

    cout << number.at(x - 1) << endl;
}
