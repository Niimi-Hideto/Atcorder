#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    for (int i = 0; i < n; i += 2) {
        sum += vec.at(i);
    }
    cout << sum << endl;
}
