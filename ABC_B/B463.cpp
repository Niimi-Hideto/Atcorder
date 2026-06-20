#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char x;
    cin >> n >> x;
    bool flag = false;

    vector<vector<char>> seat(n, vector<char>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> seat.at(i).at(j);
        }
    }

    if (x == 'A') {
        for (int i = 0; i < n; i++) {
            if (seat.at(i).at(0) == 'o') {
                flag = true;
                break;
            }
        }
    }
    else if (x == 'B') {
        for (int i = 0; i < n; i++) {
            if (seat.at(i).at(1) == 'o') {
                flag = true;
                break;
            }
        }
    }
    else if (x == 'C') {
        for (int i = 0; i < n; i++) {
            if (seat.at(i).at(2) == 'o') {
                flag = true;
                break;
            }
        }
    }
    else if (x == 'D') {
        for (int i = 0; i < n; i++) {
            if (seat.at(i).at(3) == 'o') {
                flag = true;
                break;
            }
        }
    }
    else if (x == 'E') {
        for (int i = 0; i < n; i++) {
            if (seat.at(i).at(4) == 'o') {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}

// x - 'A' で列インデックスを取得し、if/elseをまとめる別解
// int col = x - 'A';
// for (int i = 0; i < n; i++) {
//     if (seat.at(i).at(col) == 'o') {
//         flag = true;
//         break;
//     }
// }
