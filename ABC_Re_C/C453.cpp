#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i);
        l.at(i) *= 2;
    }

    int ans = 0;
    for (int b = 0; b < (1 << n); b++) {
        int tmp = 0;
        long long position = 1;
        bool before = true;
        bool after = true;
        for (int i = 0; i < n; i++) {
            (position >= 0 ? before = true : before = false);
            bool bit_i = (b & (1 << i)) == 0;
            position += (bit_i ? -l.at(i) : +l.at(i));
            (position >= 0 ? after = true : after = false);
            if (before != after) {
                tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

// 改善点: 三項演算子で分岐しなくても、条件式自体がboolなので直接代入できる
// before = (position >= 0);
// ...
// after = (position >= 0);