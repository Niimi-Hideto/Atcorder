#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> events(m + 1);

    for (int i = 0; i < n; i++) {
        int a, d, b;
        cin >> a >> d >> b;
        events.at(1).push_back({a, 1});
        events.at(d).push_back({a, -1});
        events.at(d).push_back({b, 1});
    }

    vector<int> cnt(n + 1, 0);
    int distinct = 0;

    for (int day = 1; day <= m; day++) {
        for (pair<int, int> e : events.at(day)) {
            int color = e.first;
            int delta = e.second;
            if (delta == 1) {
                if (cnt.at(color) == 0) {
                    distinct++;
                }
                cnt.at(color)++;
            }
            else {
                cnt.at(color)--;
                if (cnt.at(color) == 0) {
                    distinct--;
                }
            }
        }
        cout << distinct << endl;
    }
}
