#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }
    string tmp;
    vector<string> table;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                tmp = s.at(i) + s.at(j);
                if (count(table.begin(), table.end(), tmp) == 0) {
                    table.push_back(tmp);
                }
            }
        }
    }
    cout << table.size() << endl;
}
