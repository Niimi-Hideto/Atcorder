#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        int tmp;
        tmp = vec.at(i - 1);
        if (count(vec.begin(), vec.end(), tmp) > 1 && tmp > 0) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            if (vec.at(i - 1) == -1) {
                for (int j = 1; j <= n; j++) {
                    if (count(vec.begin(), vec.end(), j) == 0) {
                        vec.at(i - 1) = j;
                        break;
                    }
                }
            }
        }
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    else {
        cout << "No" << endl;
    }
}

// 【改善版】範囲for文で 1始まりのオフセット（i-1）が消える
// int tmp = vec.at(i - 1); の宣言と代入も1行にまとめられる
// for (int x : vec) {
//     if (x > 0 && count(vec.begin(), vec.end(), x) > 1) {
//         flag = false;
//         break;
//     }
// }
