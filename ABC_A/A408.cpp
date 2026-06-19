#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    bool flag = true;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }


    if (s < (int)vec.at(0)) {
        flag = false;
    }

    for (int i = 0; i < n - 1; i++) {
        if ((vec.at(i + 1) - vec.at(i)) > s) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

// 別解：prev=0で時刻0を起点にループ1本で済ませる
// int n, s;
// cin >> n >> s;
// bool flag = true;
// int prev = 0;
// for (int i = 0; i < n; i++) {
//     int t;
//     cin >> t;
//     if (t - prev > s) {
//         flag = false;
//     }
//     prev = t;
// }
// if (flag) {
//     cout << "Yes" << endl;
// }
// else {
//     cout << "No" << endl;
// }
