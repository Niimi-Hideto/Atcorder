#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    vector<string> table;
    string tmp = "";
    int ans = 0;
    for (int i = 0; i < (n - m + 1); i++) {
        for (int j = 0; j < (n - m + 1); j++) {
            for (int k = i; k < i + m; k++) {
                for (int l = j; l < j + m; l++) {
                    tmp += vec.at(k).at(l);
                }
            }
            if (count(table.begin(), table.end(), tmp) == 0) {
                table.push_back(tmp);
                ans++;
            }
            tmp = "";
        }
    }
    cout << ans << endl;
}
