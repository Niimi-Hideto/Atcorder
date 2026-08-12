#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.at(a).push_back(b);
    }

    vector<bool> visited(n + 1, false);
    queue<int> que;
    visited.at(1) = true;
    que.push(1);
    int cnt = 1;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int next : graph.at(cur)) {
            if (!visited.at(next)) {
                visited.at(next) = true;
                cnt++;
                que.push(next);
            }
        }
    }

    cout << cnt << endl;
}
