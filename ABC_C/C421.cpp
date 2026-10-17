#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // A がある位置を左から順に集める（0 始まり）
    vector<int> pos;
    for (int i = 0; i < 2 * n; i++) {
        if (s.at(i) == 'A') {
            pos.push_back(i);
        }
    }

    // A どうしを入れ替えても意味がないので、A は追い越さない。左から k 番目の A は、ゴールでも k 番目の A
    // ABAB… なら k 番目の A は 2k へ、BABA… なら 2k + 1 へ。動く距離の合計が入れ替えの回数
    long long cost_a = 0, cost_b = 0;
    for (int k = 0; k < n; k++) {
        cost_a += abs(pos.at(k) - 2 * k);
        cost_b += abs(pos.at(k) - (2 * k + 1));
    }

    cout << min(cost_a, cost_b) << endl;
}
