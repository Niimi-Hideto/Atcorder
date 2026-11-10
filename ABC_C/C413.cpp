#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    /* 自分で書いたもの（c × x の累積和は最大 2×10^5 × 10^18 になって long long でも溢れる。
       pre_pos も int だと 2×10^14 で溢れる。また for の条件が query だけなので 1 回も回らない）
    vector<long long> pre_x;
    vector<int> pre_pos;
    long long pos = 0;
    for (int query = 0; query; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long c, x;
            cin >> c >> x;

            if (!pre_x.empty()) {
                pre_x.push_back(pre_x.back() + (c * x));
            }
            else {
                pre_x.push_back(c * x);
            }
            if (!pre_pos.empty()) {
                pre_pos.push_back(pre_pos.back() + c);
            }
            else {
                pre_pos.push_back(c);
            }
        }
        else {
            long long k;
            cin >> k;


        }
    }
    */

    // A を展開せず、(値 x, 個数 c) のまとまりで持つ。末尾に足して先頭から消すので queue
    queue<pair<long long, long long>> a;

    for (int query = 0; query < q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long c, x;
            cin >> c >> x;
            a.push({ x, c });
        }
        else {
            long long k;
            cin >> k;

            long long sum = 0;
            // 消す残りが 0 になるまで、先頭のまとまりから使う
            while (k > 0) {
                long long x = a.front().first;
                long long c = a.front().second;

                if (c <= k) {
                    // まとまりを丸ごと消す
                    sum += x * c;
                    k -= c;
                    a.pop();
                }
                else {
                    // k 個だけ使って、残りの個数を書き換える
                    sum += x * k;
                    a.front().second -= k;
                    k = 0;
                }
            }

            cout << sum << endl;
        }
    }
}
