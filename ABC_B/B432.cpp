#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;

    sort(x.begin(), x.end());
    int zero = 0;
    zero = count(x.begin(), x.end(), '0');

    string ans;

    for (int i = zero; i < x.size(); i++) {
        if (i == zero) {
            ans += x.at(i);
            ans += string(zero, '0');
        }
        else {
            ans += x.at(i);
        }
    }
    cout << ans << endl;
}
