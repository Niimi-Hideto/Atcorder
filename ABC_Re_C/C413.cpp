#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<pair<long long, long long>> que;
    for (int query = 0; query < q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long c, x;
            cin >> c >> x;

            que.push({ c, x });
        }
        else {
            long long k;
            cin >> k;

            long long ans = 0;
            while (k > 0) {
                pair<long long, long long> front = que.front();
                if (k >= front.first) {
                    ans += (front.first * front.second);
                    k -= front.first;
                    que.pop();
                }
                else {
                    ans += (k * front.second);
                    que.front().first = front.first - k;
                    k = 0;
                }
            }
            cout << ans << endl;
        }
    }
}

/* 改善点（変わる行だけ）

// ① 33行目：コピーした front から計算し直さなくても、先頭を直接 -= で減らせば同じ
                    que.front().first -= k;
//    （25行目を参照 & にすれば front.first -= k; とも書ける）
                pair<long long, long long>& front = que.front();
                    front.first -= k;

// ② 27・32行目：外側のかっこはいらない
                    ans += front.first * front.second;
                    ans += k * front.second;
*/
