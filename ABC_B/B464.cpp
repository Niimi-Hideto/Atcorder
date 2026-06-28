#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int h0_line = 0;
    int h1_line = 0;
    int w0_line = 0;
    int w1_line = 0;

    vector<vector<char>> vec(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> vec.at(i).at(j);
        }
    }

    bool tmp = true;
    for (int i = 0; i < h; i++) {
        if (tmp) {
            for (int j = 0; j < w; j++) {
                if (vec.at(i).at(j) == '#') {
                    tmp = false;
                    break;
                }
            }
            if (tmp) {
                h0_line++;
            }
        }
    }

    tmp = true;
    for (int i = h - 1; i >= 0; i--) {
        if (tmp) {
            for (int j = w - 1; j >= 0; j--) {
                if (vec.at(i).at(j) == '#') {
                    tmp = false;
                    break;
                }
            }
            if (tmp) {
                h1_line++;
            }
        }
    }

    tmp = true;
    for (int i = 0; i < w; i++) {
        if (tmp) {
            for (int j = 0; j < h; j++) {
                if (vec.at(j).at(i) == '#') {
                    tmp = false;
                    break;
                }
            }
            if (tmp) {
                w0_line++;
            }
        }
    }

    tmp = true;
    for (int i = w - 1; i >= 0; i--) {
        if (tmp) {
            for (int j = h - 1; j >= 0; j--) {
                if (vec.at(j).at(i) == '#') {
                    tmp = false;
                    break;
                }
            }
            if (tmp) {
                w1_line++;
            }
        }
    }

    for (int i = h0_line; i < h - h1_line; i++) {
        for (int j = w0_line; j < w - w1_line; j++) {
            cout << vec.at(i).at(j);
        }
        cout << endl;
    }

}

// 外側ループを break で抜く書き方（行ごとにローカルな empty フラグを使う）
// for (int i = 0; i < h; i++) {
//     bool empty = true;
//     for (int j = 0; j < w; j++) {
//         if (vec.at(i).at(j) == '#') {
//             empty = false;
//             break;
//         }
//     }
//     if (!empty) break;
//     h0_line++;
// }