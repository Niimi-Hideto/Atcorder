#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        pair<int, int> tmp;
        cin >> tmp.first;
        tmp.second = i;

        a.at(i) = tmp;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        set<int> s;
        for (int j = 0; j < k; j++) {
            int b;
            cin >> b;
            s.insert(b);
        }
        for (int j = 1; j < k + 2; j++) {
            if (!s.count(a.at(j).second)) {
                cout << a.at(j).first << endl;
                break;
            }
        }
    }
}
