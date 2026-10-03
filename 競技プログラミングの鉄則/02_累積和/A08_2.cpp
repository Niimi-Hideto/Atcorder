#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> hw(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int x;
            cin >> x;

            hw.at(i).at(j) = x;
        }
    }

    //横の累積
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            hw.at(i).at(j) += hw.at(i).at(j - 1);
        }
    }
    //縦の累積
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            hw.at(i).at(j) += hw.at(i - 1).at(j);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int answer = hw.at(c).at(d) - hw.at(a - 1).at(d) - hw.at(c).at(b - 1) + hw.at(a - 1).at(b - 1);
        cout << answer << endl;
    }
}

/* ===== 改善点 =====
   1. 累積したあとの表には「左上からの合計」が入るので、hw より sum などの名前にすると 38 行目が読みやすい
   2. いったん x で受けなくても、表に直接読み込める

   vector<vector<int>> sum(h + 1, vector<int>(w + 1));
   cin >> sum.at(i).at(j);
*/
