#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n + 1);
    vector<vector<pair<int, int>>> event(m + 1);

    for (int i = 0; i < n; i++) {
        int d;
        pair<int, int> ab;
        cin >> ab.first >> d >> ab.second;

        event.at(d).push_back(ab);
        cnt.at(ab.first)++;
    }

    int distinct = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt.at(i) > 0) {
            distinct++;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (pair<int, int> tmp : event.at(i)) {
            cnt.at(tmp.first)--;
            if (cnt.at(tmp.first) == 0) {
                distinct--;
            }

            cnt.at(tmp.second)++;
            if (cnt.at(tmp.second) == 1) {
                distinct++;
            }
        }
        cout << distinct << endl;
    }
}

// 改善点: 初期distinctを求める2周目のループ(20〜25行目)は読み込みループに統合できる
// for (int i = 0; i < n; i++) {
//     int d;
//     pair<int, int> ab;
//     cin >> ab.first >> d >> ab.second;
//
//     event.at(d).push_back(ab);
//     cnt.at(ab.first)++;
//     if (cnt.at(ab.first) == 1) distinct++;
// }
// ↑これで distinct の初期値も一緒に求まるので、20〜25行目のループが丸ごと不要になる
