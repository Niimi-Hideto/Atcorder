#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ans(m, -1);

    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;

        ans.at(c - 1) = max(ans.at(c - 1), s);
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
