#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<string>> vec(h, vector<string>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> vec.at(i).at(j);
        }
    }

    int count = 0;
    count += h * w;



    //横の時
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vec.at(i).at(j) == vec.at(i).at(j + 1)) {
                count++;
            }
        }
    }

    //解けなかった．
}

// 模範解答
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int h, w;
//     cin >> h >> w;
//
//     vector<string> grid(h);
//     for (int i = 0; i < h; i++) cin >> grid.at(i);
//
//     int cnt = 0;
//     for (int h1 = 0; h1 < h; h1++) {
//         for (int h2 = h1; h2 < h; h2++) {
//             for (int w1 = 0; w1 < w; w1++) {
//                 for (int w2 = w1; w2 < w; w2++) {
//                     bool ok = true;
//                     for (int i = h1; i <= h2; i++) {
//                         for (int j = w1; j <= w2; j++) {
//                             if (grid.at(i).at(j) != grid.at(h1+h2-i).at(w1+w2-j)) {
//                                 ok = false;
//                             }
//                         }
//                     }
//                     if (ok) cnt++;
//                 }
//             }
//         }
//     }
//     cout << cnt << endl;
// }
