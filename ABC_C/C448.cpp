#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n); // (値, 元のインデックス)
    for (int i = 0; i < n; i++) {
        cin >> a.at(i).first;
        a.at(i).second = i + 1;
    }
    sort(a.begin(), a.end());

    int limit = min(n, 6);

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        vector<int> b(k);
        for (int j = 0; j < k; j++) {
            cin >> b.at(j);
        }

        for (int j = 0; j < limit; j++) {
            int idx = a.at(j).second;
            bool removed = false;
            for (int x : b) {
                if (x == idx) {
                    removed = true;
                    break;
                }
            }
            if (!removed) {
                cout << a.at(j).first << endl;
                break;
            }
        }
    }
}
