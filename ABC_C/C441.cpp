#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    long long x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end()); // 昇順

    // 戦略：残り(N-K)個（Kの中に入らない、必ず日本酒じゃありえないカップ以外の大きい方）は
    // 常に全部選ぶ。それに加えて「Kの中で大きい方から」何個か選び足す。
    // Kの中で除外する（選ばない）のは小さい方からにするのが最善
    // →「Kの中で保証できる量」を増やしたいので、選ぶのはKの中の大きい方から
    long long ml = 0;
    int cnt = 0;
    for (int i = k - 1; i >= 0; i--) { // Kの中の大きい方から順に
        ml += a.at(i);
        cnt++;
        if (ml >= x) {
            break;
        }
    }

    cout << (ml >= x ? cnt + (n - k) : -1) << endl;
}
