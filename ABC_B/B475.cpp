#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans(3, 0);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        a %= 1000;
        int tmp = 1000 - a;

        int j = 0;
        while (j < 3) {
            ans.at(j) += tmp % 10;
            tmp /= 10;
            j++;
        }

    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

// 改善案：
// ①繰り返し回数が3回と決まっているので、whileよりforが素直（ABC450 A→ABC470 Aに続き3回目の指摘）
//
//     for (int j = 0; j < 3; j++) {
//         ans.at(j) += tmp % 10;
//         tmp /= 10;
//     }
//
// ②Aが1000の倍数のとき tmp = 1000 になるが、下3桁しか読まないので結果的に0枚で正しく動く。
//   ただし「なぜ正しいか」がコードから読み取れないので、意図を式に出した方がよい：
//
//     int tmp = (1000 - a % 1000) % 1000;   // ちょうど払えるときはお釣り0
