#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    // |X| = max(X, −X) なので、|表の総和| + |裏の総和| は
    // 「表を + か − か」「裏を + か − か」の 4 通りの (±表の総和) + (±裏の総和) のうち最大と同じ
    // 符号を 1 つ固定すると、カード i の得点 (sa × A_i + sb × B_i) を足すだけになり、
    // カード同士は影響しないので、得点がプラスのカードを全部選べば最大
    vector<int> sign = {1, -1};
    long long ans = 0;
    for (int sa : sign) {
        for (int sb : sign) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                long long score = sa * a.at(i) + sb * b.at(i);  // カード i を選んだときの損得
                if (score > 0) {
                    sum += score;
                }
            }
            ans = max(ans, sum);
        }
    }

    // 合計は最大 10^5 × 2×10^9 = 2×10^14 なので long long
    cout << ans << endl;
}
