#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    //priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int value;
            cin >> value;

            pq.push(value);
        }
        else if (type == 2) {
            cout << pq.top() << endl;
        }
        else {
            pq.pop();
        }
    }
}
