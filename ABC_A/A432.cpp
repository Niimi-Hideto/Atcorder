#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> v = { a, b, c };
    sort(v.rbegin(), v.rend());

    cout << v.at(0) * 100 + v.at(1) * 10 + v.at(2) << endl;
}
