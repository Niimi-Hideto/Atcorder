#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<string> s;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            string b;
            cin >> b;

            s.push(b);
        }
        else if (type == 2) {
            cout << s.top() << endl;
        }
        else {
            s.pop();
        }
    }
}
