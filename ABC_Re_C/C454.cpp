#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<vector<int>> ab(n + 1);
    vector<bool> visited(n + 1);
    visited.at(1) = true;
    int ans = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            q.push(b);
        }
        ab.at(a).push_back(b);
    }

    while (q.size() > 0) {
        int tmp = q.front();
        q.pop();

        if (visited.at(tmp) == false) {
            visited.at(tmp) = true;
            ans++;

            for (int item : ab.at(tmp)) {
                q.push(item);
            }
        }
    }
    cout << ans << endl;
}
