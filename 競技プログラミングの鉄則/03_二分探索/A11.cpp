#include <bits/stdc++.h>
using namespace std;

// ソート済みの a の中で、x が何番目にあるかを返す（1始まり）。見つからなければ -1
int search_pos(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;   // 探索範囲（0始まりの添字）

    // 範囲が空になる（l > r）まで続ける。l == r の1つだけになっても調べる
    while (l <= r) {
        int mid = (l + r) / 2;

        if (a.at(mid) == x) {
            return mid + 1;      // 見つけたその場で返す（1始まりに直す）
        }
        else if (a.at(mid) < x) {
            l = mid + 1;         // x は mid より右にある
        }
        else {
            r = mid - 1;         // x は mid より左にある
        }
    }

    return -1;   // 範囲が空になった＝どこにもなかった
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    cout << search_pos(a, x) << endl;
}
