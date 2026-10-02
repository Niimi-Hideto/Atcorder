#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        char t;
        int a;
        cin >> t >> a;

        if (t == '+') {
            sum += a;
        }
        else if (t == '-') {
            sum -= a;
        }
        else if (t == '*') {
            sum *= a;
        }

        // 足し算・引き算・掛け算は、途中で何度余りを取っても最後の余りは変わらない。
        // 毎回余りに置き換えておけば sum は常に 10000 未満で、掛けても溢れない
        sum %= 10000;

        // C++ の % はマイナスの数だとマイナスの余りを返す（-20 % 10000 = -20）。
        // sum は 0〜9999 から最大 100 引くだけなので、マイナスなら 10000 足せば正の余りになる
        if (sum < 0) {
            sum += 10000;
        }

        cout << sum << endl;
    }
}
