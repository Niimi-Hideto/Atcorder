#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> start(n);
    vector<int> end(n);
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> start.at(i) >> end.at(i);
    }

    for (int i = 0; i < n; i++) {
        if ((start.at(i) <= l) && (end.at(i) >= r)) {
            count++;
        }
    }
    cout << count << endl;
}

// 別解：vectorなしで読み込みと判定を同時に
// for (int i = 0; i < n; i++) {
//     int x, y;
//     cin >> x >> y;
//     if (x <= l && y >= r) count++;
// }
