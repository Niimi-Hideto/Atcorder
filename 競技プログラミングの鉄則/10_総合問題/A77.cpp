#include <bits/stdc++.h>
using namespace std;

// 「どのピースも x 以上にして、K 回以上切れるか」を判定する
// 前から見て、前に切った場所から x 以上、かつ右端まで x 以上残るなら、そこで切る（早く切れるなら早く切るのが得）
bool check(int x, const vector<int>& a, int n, int l, int k) {
    int cnt = 0;   // 切った回数
    int last = 0;  // 最後に切った場所（最初は左端の 0）
    for (int i = 1; i <= n; i++) {
        if (a.at(i) - last >= x && l - a.at(i) >= x) {
            cnt++;
            last = a.at(i);
        }
    }
    return cnt >= k;
}

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    /* 自分で書いたもの（区間の長さを小さい順に並べて累積し、L / (K + 1) に近いところを探していた。
       並べ替えると切れ目の位置関係がなくなるので、実際にその長さのピースが作れるとは限らない）
    a.push_back(l);

    vector<int> dif(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        dif.at(i) = a.at(i) - a.at(i - 1);
    }
    sort(dif.begin(), dif.end());

    vector<int> pre_dif(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        pre_dif.at(i) = pre_dif.at(i - 1) + dif.at(i);
    }

    int cut = l / (k + 1);
    auto it = lower_bound(pre_dif.begin(), pre_dif.end(), cut);
    it--;

    cout << *it << endl;
    */

    // 答えで二分探索：check(x) は x が小さいうちは true、ある値を超えると false
    // true になる一番大きい x を探す
    int left = 1, right = l;  // 答えは 1 以上 L 以下
    while (left < right) {
        int mid = (left + right + 1) / 2;  // left = mid にするので切り上げ（切り捨てだと範囲が縮まらず無限ループ）
        if (check(mid, a, n, l, k)) {
            left = mid;       // mid にはできる → 答えは mid 以上
        }
        else {
            right = mid - 1;  // mid にはできない → 答えは mid − 1 以下
        }
    }

    cout << left << endl;
}
