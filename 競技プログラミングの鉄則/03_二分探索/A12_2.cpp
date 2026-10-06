#include <bits/stdc++.h>
using namespace std;

// x 秒までに刷れる枚数が k 枚以上なら true（＝答えは x 以下）
bool check(long long x, long long k, vector<long long> &a) {
    long long sum = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        sum += x / a.at(i);  // プリンター i が x 秒までに刷る枚数（切り捨て）
    }
    return sum >= k;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    // 答え（秒数）を 1〜10^9 の範囲で二分探索する
    // check は false…false true…true と切り替わるので、最初の true を探す
    long long left = 1, right = 1000000000;
    while (left < right) {  // 範囲が 1 つに絞られたら終わり
        long long mid = (left + right) / 2;
        if (check(mid, k, a)) {
            right = mid;      // mid でも間に合う → 答えは mid 以下（mid も候補なので残す）
        }
        else {
            left = mid + 1;   // mid では足りない → 答えは mid + 1 以上
        }
    }

    // 抜けたとき left == right で、それが答え
    cout << left << endl;
}
