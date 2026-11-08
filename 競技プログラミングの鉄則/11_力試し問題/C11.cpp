/* 自分で書いたもの
   （「票数 ÷ 議席数」の大きい順に 1 議席ずつ配るのはドント方式の定義どおりだが、
   K ≤ 10^9 回ループして毎回 priority_queue を動かすので約 1.7×10^10 回で TLE。
   票数を整数の割り算で上書きしているので、切り捨てた分が戻らず比べる値もずれる）

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<tuple<int, int, int>> q;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        q.push({ a, i, 1 });
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= k; i++) {
        int vote, candidate, cnt;
        tie(vote, candidate, cnt) = q.top();
        q.pop();

        ans.at(candidate)++;

        vote *= cnt;
        cnt++;
        vote /= cnt;

        q.push({ vote, candidate, cnt });
    }

    for (int i = 1; i <= n; i++) {
        cout << ans.at(i);
        if (i != n) {
            cout << " ";
        }
    }
    cout << endl;
}
*/

#include <bits/stdc++.h>
using namespace std;

// ボーダーを x としたとき、全部の党で合わせて何議席になるか
// （A 票の党は A ÷ 1, A ÷ 2, … のうち x 以上のものの個数 ＝ A ÷ x の切り捨て議席）
long long count_seats(double x, const vector<long long>& a, int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (long long)(a.at(i) / x);
    }
    return sum;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    // ボーダー x を実数で二分探索する（制約より 1 < x < 10^9）
    double left = 1, right = 1000000000;
    double border = left;
    for (int t = 0; t < 100; t++) {
        double mid = (left + right) / 2;
        long long seats = count_seats(mid, a, n);

        if (seats == k) {
            // ちょうど K 議席になる x が見つかった
            border = mid;
            break;
        }
        else if (seats > k) {
            // 議席が多すぎる → ボーダーを上げる
            left = mid;
        }
        else {
            // 議席が足りない → ボーダーを下げる
            right = mid;
        }
    }

    // 見つかったボーダーで、各党の議席 = A ÷ x の切り捨て
    for (int i = 1; i <= n; i++) {
        cout << (long long)(a.at(i) / border);
        if (i != n) {
            cout << " ";
        }
    }
    cout << endl;
}
