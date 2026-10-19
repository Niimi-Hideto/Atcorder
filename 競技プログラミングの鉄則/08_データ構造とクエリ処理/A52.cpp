#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<string> que;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            string s;
            cin >> s;

            que.push(s);
        }
        else if (type == 2) {
            cout << que.front() << endl;
        }
        else {
            que.pop();
        }
    }
}
