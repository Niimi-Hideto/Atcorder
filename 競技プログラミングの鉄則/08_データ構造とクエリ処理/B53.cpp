#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> job(d + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        job.at(x).push_back(y);
    }

    priority_queue<int> q;
    long long ans = 0;
    for (int i = 1; i <= d; i++) {
        for (int y : job.at(i)) {
            q.push(y);
        }

        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << endl;
}
