#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    if (h == 1 && w == 1) {
        cout << 0 << endl;
    }
    else if (h == 1) {
        for (int i = 1; i < w + 1; i++) {
            if (i == 1 || i == w) {
                cout << 1 << " ";
            }
            else {
                cout << 2 << " ";
            }
        }
        cout << endl;
    }
    else if (w == 1) {
        for (int i = 1; i < h + 1; i++) {
            if (i == 1 || i == h) {
                cout << 1 << " ";
            }
            else {
                cout << 2 << " ";
            }
            cout << endl;
        }
    }
    else {
        for (int i = 1; i < h + 1; i++) {
            for (int j = 1; j < w + 1; j++) {
                if ((i == 1 && j == 1) || (i == h && j == 1)
                    || (i == 1 && j == w) || (i == h && j == w)) {
                    cout << 2 << " ";
                }
                else if ((i == 1) || (j == 1) || (i == h) || (j == w)) {
                    cout << 3 << " ";
                }
                else {
                    cout << 4 << " ";
                }
            }
            cout << endl;
        }
    }
}

// bool加算版（シンプル）
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int h, w;
//     cin >> h >> w;
//
//     for (int i = 1; i <= h; i++) {
//         for (int j = 1; j <= w; j++) {
//             cout << (i > 1) + (i < h) + (j > 1) + (j < w);
//             if (j < w) cout << " ";
//         }
//         cout << endl;
//     }
// }
