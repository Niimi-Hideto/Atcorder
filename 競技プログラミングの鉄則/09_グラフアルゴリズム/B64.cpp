#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//
//     vector<vector<pair<int, int>>> g(n + 1);
//     for (int i = 1; i <= m; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//
//         g.at(a).push_back({ b, c });
//         g.at(b).push_back({ a, c });
//     }
//
//     long long INF = (1 << 60);
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
//     vector<pair<long long, int>> dist(n + 1, { INF, -1 });
//     vector<bool> visited(n + 1);
//     visited.at(1) = true;
//     for (pair<int, int> x : g.at(1)) {
//         q.push({ x.second, x.first });
//
//         dist.at(x.first) = { x.second, 1 };
//     }
//
//     while (!q.empty()) {
//         pair<long long, int> pos = q.top();
//         q.pop();
//
//         visited.at(pos.second) = true;
//         for (pair<long long, int> x : g.at(pos.second)) {
//             if (!visited.at(x.first)) {
//                 if (dist.at(x.first).first > x.second + dist.at(pos.second).first) {
//                     dist.at(x.first) = { x.second + dist.at(pos.second).first, pos.second };
//                 }
//
//                 q.push({ dist.at(x.first).first ,x.first });
//             }
//         }
//     }
//
//     for (int i = 1; i <= n; i++) {
//         cout << dist.at(i).first << endl;
//     }
// }

const long long INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g.at(a).push_back({ b, c });
        g.at(b).push_back({ a, c });
    }

    vector<long long> dist(n + 1, INF);
    vector<int> from(n + 1, -1);
    vector<bool> done(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist.at(1) = 0;
    q.push({ 0, 1 });

    while (!q.empty()) {
        int pos = q.top().second;
        q.pop();

        if (done.at(pos)) {
            continue;
        }
        done.at(pos) = true;

        for (pair<int, int> e : g.at(pos)) {
            int nex = e.first;
            int cost = e.second;
            if (dist.at(nex) > dist.at(pos) + cost) {
                dist.at(nex) = dist.at(pos) + cost;
                from.at(nex) = pos;
                q.push({ dist.at(nex), nex });
            }
        }
    }

    vector<int> path;
    for (int v = n; v != -1; v = from.at(v)) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++) {
        if (i >= 1) {
            cout << " ";
        }
        cout << path.at(i);
    }
    cout << endl;
}
