#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    string s;

    cin >> n >> d >> s;

    cout << n - (count(s.begin(), s.end(), '@') - d) << endl;
}
