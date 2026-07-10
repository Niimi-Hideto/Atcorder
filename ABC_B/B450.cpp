#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // cost[i][j] = 駅iから駅jへのコスト（1-indexed）
    vector<vector<long long>> cost(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> cost.at(i).at(j);  // 入力は上三角行列で与えられる
        }
    }

    // a < b < c の全組み合わせを3重ループで試す
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            for (int c = b + 1; c <= n; c++) {
                // 途中下車の合計コスト < 直接乗車のコスト なら Yes
                if (cost.at(a).at(b) + cost.at(b).at(c) < cost.at(a).at(c)) {
                    cout << "Yes" << endl;
                    return 0;  // 1つ見つかったら即終了
                }
            }
        }
    }

    cout << "No" << endl;
}
