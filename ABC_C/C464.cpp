#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // cnt[色] = 今その色の鳥が何羽いるか
    vector<int> cnt(n + 1, 0);
    int distinct = 0;

    // events[日付] に {色, +1か-1} を積む
    vector<vector<pair<int, int>>> events(m + 1);

    for (int i = 1; i <= n; i++) {
        int a, d, b;
        cin >> a >> d >> b;

        // 初期: 色 A を +1
        cnt.at(a)++;
        if (cnt.at(a) == 1) distinct++;

        // D 日目に色 A を -1、色 B を +1
        events.at(d).push_back({a, -1});
        events.at(d).push_back({b, +1});
    }

    for (int j = 1; j <= m; j++) {
        for (auto ev : events.at(j)) {
            int color = ev.first;
            int delta = ev.second;
            if (delta == +1) {
                cnt.at(color)++;
                if (cnt.at(color) == 1) distinct++;
            } else {
                cnt.at(color)--;
                if (cnt.at(color) == 0) distinct--;
            }
        }
        cout << distinct << "\n";
    }
}
