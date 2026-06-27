#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n + 1; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += n / 10;
        }
    }
}
//解けなかった．

/*
int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int tmp = i;
        while (tmp > 0) {
            sum += tmp % 10;  // 1の位を取り出して足す
            tmp /= 10;        // 1の位を消す
        }
        if (sum == k) count++;
    }
    cout << count << endl;
}
*/
