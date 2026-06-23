#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == w - 1) {
                cout << '#' << endl;
            }
            else if (i == 0 || j == 0 || i == h - 1) {
                cout << '#';
            }

            else {
                cout << '.';
            }
        }
    }
}

// シンプル版
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int h, w;
//     cin >> h >> w;
//
//     for (int i = 0; i < h; i++) {
//         for (int j = 0; j < w; j++) {
//             if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
//                 cout << '#';
//             else
//                 cout << '.';
//         }
//         cout << endl;
//     }
// }