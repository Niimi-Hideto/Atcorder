#include <bits/stdc++.h>
using namespace std;

// x 秒までに K 枚以上刷れているか？
// プリンター i は x 秒までに x / A_i 枚（切り捨て）刷るので、全台分足すだけ
bool check(const vector<long long>& a, long long k, long long x) {
    long long sum = 0;   // 最大 10^5 × 10^9 = 10^14 なので long long
    for (int i = 0; i < (int)a.size(); i++) {
        sum += x / a.at(i);
    }
    return sum >= k;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    // check は x が大きいほど true になりやすい（false … false true … true）。
    // 探すのは「最初に true になる x」。答えは 1〜10^9 の中に必ずある
    long long left = 1, right = 1000000000;

    // 範囲を1つに絞るまで続ける（left == right で終わる）
    while (left < right) {
        long long mid = (left + right) / 2;

        if (check(a, k, mid)) {
            right = mid;       // mid も答えの候補なので範囲に残す
        }
        else {
            left = mid + 1;    // mid では足りないと確定したので外す
        }
    }

    // 絞り終わった1つが「最初に true になる x」
    cout << left << endl;
}
