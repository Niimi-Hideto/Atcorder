#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n + 1, 0);
    int distinct = 0;

    vector<vector<pair<int, int>>> events(m + 1);

    for (int i = 0; i < n; i++) {
        int a, d, b;
        cin >> a >> d >> b;

        int start_color = a;
        if (d == 1) {
            start_color = b;
        }
        cnt.at(start_color)++;
        if (cnt.at(start_color) == 1) distinct++;

        if (d >= 2) {
            events.at(d).push_back({a, -1});
            events.at(d).push_back({b, +1});
        }
    }

    for (int j = 1; j <= m; j++) {
        for (auto ev : events.at(j)) {
            int color = ev.first;
            int delta = ev.second;
            if (delta == +1) {
                cnt.at(color)++;
                if (cnt.at(color) == 1) distinct++;
            }
            else {
                cnt.at(color)--;
                if (cnt.at(color) == 0) distinct--;
            }
        }
        cout << distinct << endl;
    }
}
