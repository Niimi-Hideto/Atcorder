#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> gift(n);

    int k;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            gift.at(tmp - 1).push_back(i + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << gift.at(i).size() << " ";
        for (int j = 0; j < gift.at(i).size(); j++) {
            cout << gift.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

// 範囲for文バージョン（出力部分）
// for (int i = 0; i < n; i++) {
//     cout << gift.at(i).size() << " ";
//     for (int x : gift.at(i)) {
//         cout << x << " ";
//     }
//     cout << endl;
// }
