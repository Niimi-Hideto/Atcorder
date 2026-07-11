#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    deque<int> dq;
    int c = 0;  // 反転した回数

    for (int k = 1; k <= n; k++) {
        if (c % 2 == 0) {
            dq.push_back(k);   // 偶数回反転済み → 末尾に追加
        } else {
            dq.push_front(k);  // 奇数回反転済み → 先頭に追加
        }
        if (s.at(k - 1) == 'o') c++;  // 反転操作が来たら回数を増やす
    }

    // c が奇数なら1回分の反転が残っている
    if (c % 2 == 1) {
        reverse(dq.begin(), dq.end());
    }
    for (int x : dq) {
        cout << x << " ";
    }
    cout << "\n";
}
