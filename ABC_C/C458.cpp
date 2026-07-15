#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int size = (int)s.size();

    long long ans = 0;
    for (int i = 0; i < size; i++) {
        if (s.at(i) == 'C') {
            ans++;
            if (size % 2 == 0) {
                if (i < (size / 2)) {
                    for (int j = 0; j < i; j++) {
                        ans++;
                    }
                }
                else {
                    for (int j = 0; j < (size - 1 - i); j++) {
                        ans++;
                    }
                }
            }
            else {
                if (i <= (size / 2)) {
                    for (int j = 0; j < i; j++) {
                        ans++;
                    }
                }
                else {
                    for (int j = 0; j < (size - 1 - i); j++) {
                        ans++;
                    }
                }
            }

        }
    }
    cout << ans << endl;
}

// 改善点: size の偶奇での場合分けと内側ループは不要。min で O(N) に書ける
// long long ans = 0;
// for (int i = 0; i < size; i++) {
//     if (s.at(i) == 'C') {
//         ans += min(i, size - 1 - i) + 1;
//     }
// }
