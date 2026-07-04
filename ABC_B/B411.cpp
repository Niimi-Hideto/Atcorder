#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> d.at(i);
    }


    cout << d.at(0) << " ";
    for (int i = 1; i < n - 1; i++) {

        d.at(i) = d.at(i) + d.at(i - 1);
        cout << d.at(i) << " ";
    }
    cout << endl;
    while ((int)d.size() > 1) {
        int tmp = d.at(0);
        d.erase(d.begin());
        for (int i = 0; i < (int)d.size(); i++) {
            d.at(i) = d.at(i) - tmp;
            cout << d.at(i) << " ";
        }
        cout << endl;
    }
}

// 【改善版】d を書き換えず、2重ループで dist を足し込む
// for (int i = 0; i < n - 1; i++) {      // i = 出発駅のインデックス（0始まり）
//     int dist = 0;                       // 出発駅からの累積距離。iが変わるたびに0にリセット
//     for (int j = i; j < n - 1; j++) {  // j = D[j]（駅j→駅j+1の距離）を足していく
//         dist += d.at(j);               // dist に隣接距離を1つずつ足す → 出発駅から駅(j+1)までの距離になる
//         cout << dist;
//         if (j < n - 2) cout << " ";    // 最後の要素だけスペースなし
//     }
//     cout << endl;
// }
