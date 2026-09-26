#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h.at(i);
    }

    vector<int> dp(n + 1, 0);
    dp.at(2) = abs(h.at(2) - h.at(1));
    for (int i = 3; i <= n; i++) {
        dp.at(i) = min(dp.at(i - 2) + abs(h.at(i) - h.at(i - 2)), dp.at(i - 1) + abs(h.at(i) - h.at(i - 1)));
    }

    //最短ルートを求める
    int place = n;
    vector<int> visited;
    while (true) {
        visited.push_back(place);

        if (place == 1) {
            break;
        }
        if (dp.at(place) == dp.at(place - 1) + abs(h.at(place) - h.at(place - 1))) {
            place -= 1;
        }
        else {
            place -= 2;
        }
    }

    reverse(visited.begin(), visited.end());
    cout << visited.size() << endl;
    for (int x : visited) {
        cout << x << " ";
    }
    cout << endl;
}
