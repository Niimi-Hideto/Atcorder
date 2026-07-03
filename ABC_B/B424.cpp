#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> vec(n, vector<int>(m));


    for (int i = 0; i < k; i++) {
        bool flag = true;
        int a, b;
        cin >> a >> b;

        if (vec.at(a - 1).at(b - 1) == 0) {
            vec.at(a - 1).at(b - 1) = b;
            if (vec.at(a - 1).at(b - 1) > 0) {
                for (int x : vec.at(a - 1)) {
                    if (x == 0) {
                        flag = false;
                    }
                }
                if (flag) {
                    cout << a << " ";
                }
            }
        }
    }
    cout << endl;
}

// 【改善版】19行目の if (vec.at(a-1).at(b-1) > 0) は直前で = b を代入した直後なので常にtrue → 削除できる
// if (vec.at(a - 1).at(b - 1) == 0) {
//     vec.at(a - 1).at(b - 1) = b;
//     for (int x : vec.at(a - 1)) {
//         if (x == 0) flag = false;
//     }
//     if (flag) cout << a << " ";
// }
