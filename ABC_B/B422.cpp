


//解けませんでした．




#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    bool flag = true;

    vector<string> vec(h);
    for (int i = 0; i < h;i++) {
        cin >> vec.at(i);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            vector<char> tmp;
            if (vec.at(i).at(j) == '#') {
                if (i == 0 && j == 0) {
                    if (vec.at(1).at(0) != '#' || vec.at(0).at(1) != '#') {
                        flag = false;
                    }
                }
                else if (i == 0 && j == w - 1) {
                    if (vec.at(0).at(w - 2) != '#' || vec.at(1).at(w - 1) != '#') {
                        flag = false;
                    }
                }
                else if (i == h - 1 && j == 0) {
                    if (vec.at(h - 2).at(0) != '#' || vec.at(h - 1).at(1) != '#') {
                        flag = false;
                    }
                }
                else if (i == h - 1 && j == w - 1) {
                    if (vec.at(h - 2).at(w - 1) != '#' || vec.at(h - 1).at(w - 2) != '#') {
                        flag = false;
                    }
                }
                else if (i == 0) {
                    tmp.push_back(vec.at(i).at(j - 1));
                    tmp.push_back(vec.at(i).at(j + 1));
                    tmp.push_back(vec.at(i + 1).at(j));
                    if (count(tmp.begin(), tmp.end(), '#') != 2) {
                        flag = false;
                    }
                }
                else if (i == h - 1) {
                    tmp.push_back(vec.at(i).at(j - 1));
                    tmp.push_back(vec.at(i).at(j + 1));
                    tmp.push_back(vec.at(i - 1).at(j));
                    if (count(tmp.begin(), tmp.end(), '#') != 2) {
                        flag = false;
                    }
                }
                else if (j == 0) {
                    tmp.push_back(vec.at(i - 1).at(j));
                    tmp.push_back(vec.at(i + 1).at(j));
                    tmp.push_back(vec.at(i).at(j + 1));
                    if (count(tmp.begin(), tmp.end(), '#') != 2) {
                        flag = false;
                    }
                }
                else if (j == w - 1) {
                    tmp.push_back(vec.at(i - 1).at(j));
                    tmp.push_back(vec.at(i + 1).at(j));
                    tmp.push_back(vec.at(i).at(j - 1));
                    if (count(tmp.begin(), tmp.end(), '#') != 2) {
                        flag = false;
                    }
                }
                else {
                    tmp.push_back(vec.at(i - 1).at(j));
                    tmp.push_back(vec.at(i).at(j - 1));
                    tmp.push_back(vec.at(i + 1).at(j));
                    tmp.push_back(vec.at(i).at(j + 1));
                    if (count(tmp.begin(), tmp.end(), '#') != 2 && count(tmp.begin(), tmp.end(), '#') != 4) {
                        flag = false;
                    }
                }
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

// 【自分の方針で直した版】コーナーと上辺に h==1・w==1 のガードを追加する
// ① コーナー4箇所：vec.at(1) や vec.at(i).at(1) を触る前に h>1・w>1 チェック
// ② 上辺：vec.at(i+1) を触る前に h>1 チェック（h==1 のとき上の行が存在しない）
// ③ 下辺・左辺・右辺はコーナーが先に処理されるので変更不要
//
// if (i == 0 && j == 0) {
//     int cnt = 0;
//     if (h > 1 && vec.at(1).at(0) == '#') cnt++;
//     if (w > 1 && vec.at(0).at(1) == '#') cnt++;
//     if (cnt != 2 && cnt != 4) flag = false;
// }
// else if (i == 0 && j == w - 1) {
//     int cnt = 0;
//     if (w > 1 && vec.at(0).at(w - 2) == '#') cnt++;
//     if (h > 1 && vec.at(1).at(w - 1) == '#') cnt++;
//     if (cnt != 2 && cnt != 4) flag = false;
// }
// else if (i == h - 1 && j == 0) {
//     int cnt = 0;
//     if (h > 1 && vec.at(h - 2).at(0) == '#') cnt++;
//     if (w > 1 && vec.at(h - 1).at(1) == '#') cnt++;
//     if (cnt != 2 && cnt != 4) flag = false;
// }
// else if (i == h - 1 && j == w - 1) {
//     int cnt = 0;
//     if (h > 1 && vec.at(h - 2).at(w - 1) == '#') cnt++;
//     if (w > 1 && vec.at(h - 1).at(w - 2) == '#') cnt++;
//     if (cnt != 2 && cnt != 4) flag = false;
// }
// else if (i == 0) {
//     tmp.push_back(vec.at(i).at(j - 1));
//     tmp.push_back(vec.at(i).at(j + 1));
//     if (h > 1) tmp.push_back(vec.at(i + 1).at(j));  // h==1 のとき行が存在しない
//     if (count(tmp.begin(), tmp.end(), '#') != 2) flag = false;
// }
// （下辺・左辺・右辺・内部はそのまま）
//



// 【正解①】場合分けをせず、4方向ループ＋範囲内チェックでまとめて処理する
//
// vector<int> di = {-1, 1, 0, 0};  // 上下左右のi移動量
// vector<int> dj = {0, 0, -1, 1};  // 上下左右のj移動量
//
// for (int i = 0; i < h; i++) {
//     for (int j = 0; j < w; j++) {
//         if (vec.at(i).at(j) == '#') {
//             int cnt = 0;
//             for (int d = 0; d < 4; d++) {
//                 int ni = i + di.at(d);
//                 int nj = j + dj.at(d);
//                 if (ni >= 0 && ni < h && nj >= 0 && nj < w && vec.at(ni).at(nj) == '#') cnt++;
//             }
//             if (cnt != 2 && cnt != 4) flag = false;
//         }
//     }
// }
//
// 【正解②】グリッドを上下左右に '.' で1列パディングする（模範解答）
// → 境界チェック完全不要。端の隣は必ず '.' になる
//
// vector<string> field(h + 2, string(w + 2, '.'));  // H+2行 W+2列、全て '.'
// for (int i = 1; i <= h; i++) {
//     string s; cin >> s;
//     field.at(i) = '.' + s + '.';  // 左右にも '.' を追加
// }
// for (int i = 1; i <= h; i++) {
//     for (int j = 1; j <= w; j++) {
//         int cnt = 0;
//         if (field.at(i - 1).at(j) == '#') cnt++;
//         if (field.at(i + 1).at(j) == '#') cnt++;
//         if (field.at(i).at(j - 1) == '#') cnt++;
//         if (field.at(i).at(j + 1) == '#') cnt++;
//         if (field.at(i).at(j) == '#' && cnt != 2 && cnt != 4) {
//             cout << "No" << endl; return 0;
//         }
//     }
// }
// cout << "Yes" << endl;
