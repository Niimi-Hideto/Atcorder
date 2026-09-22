#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> pre_snow(h + 2, vector<int>(w + 2));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        pre_snow.at(a).at(b)++;
        pre_snow.at(c + 1).at(b)--;
        pre_snow.at(a).at(d + 1)--;
        pre_snow.at(c + 1).at(d + 1)++;
    }

    //横累積
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            pre_snow.at(i).at(j) += pre_snow.at(i).at(j - 1);
        }
    }
    //縦累積
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            pre_snow.at(i).at(j) += pre_snow.at(i - 1).at(j);
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << pre_snow.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
