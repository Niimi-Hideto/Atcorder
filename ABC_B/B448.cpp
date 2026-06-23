#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;

    vector<int> vec(m);

    for (int i = 0; i < m; i++) {
        cin >> vec.at(i);
    }

    for (int i = 0; i < n; i++) {
        int num;
        int much;
        cin >> num >> much;

        if (vec.at(num - 1) - much >= 0) {
            ans += much;
            vec.at(num - 1) -= much;
        }
        else {
            ans += vec.at(num - 1);
            vec.at(num - 1) = 0;
        }
    }
    cout << ans << endl;
}
