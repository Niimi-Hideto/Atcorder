#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> box(n, 0);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            box.at(x - 1)++;
            cout << x << " ";
        }
        else {
            int tmp = 1000;
            for (int j = 0; j < n; j++) {
                tmp = min(tmp, box.at(j));
            }
            for (int j = 0; j < n; j++) {
                if (box.at(j) == tmp) {
                    box.at(j)++;
                    cout << (j + 1) << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
}
