#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<int> tree;
    for (int i = 0; i < q; i++) {
        int t, h;
        cin >> t >> h;

        if (t == 1) {
            tree.insert(h);
        }
        else {
            auto it = tree.upper_bound(h);
            tree.erase(tree.begin(), it);
        }
        cout << tree.size() << endl;
    }
}
