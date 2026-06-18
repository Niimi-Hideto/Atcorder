#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, c;
    cin >> x >> c;
    int ans;
    int commission;
    int num;
    bool flag = false;
    int i = 0;

    while (flag == false) {
        ans = (1000 * i) + (c * i);
        i++;
        if (ans <= x) {
            continue;
        }
        else {
            break;
        }
    }
    ans = (1000 * (i - 2));
    cout << ans << endl;
}

// 模範解答①：整数除算（ループ不要）
// int k = x / (1000 + c);
// cout << k * 1000 << endl;

// 模範解答②：ループで書く場合（インクリメントをチェックの後に）
// int k = 0;
// while ((k + 1) * (1000 + c) <= x) {
//     k++;
// }
// cout << k * 1000 << endl;





