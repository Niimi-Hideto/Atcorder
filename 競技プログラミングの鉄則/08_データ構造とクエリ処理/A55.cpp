#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> card;
    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            card.insert(x);
        }
        else if (type == 2) {
            card.erase(x);
        }
        else if (type == 3) {
            auto itr = card.lower_bound(x);
            if (itr == card.end()) {
                cout << -1 << endl;
            }
            else {
                cout << *itr << endl;
            }
        }
    }
}
