#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(4);

    cin >> vec.at(0) >> vec.at(1) >>
        vec.at(2) >> vec.at(3);

    int ans = 0;

    for (int i = 1; i <= 4; i++) {
        ans += (count(vec.begin(), vec.end(), i) / 2);
    }

    cout << ans << endl;
}
