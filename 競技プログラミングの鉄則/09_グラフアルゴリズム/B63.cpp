#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;

    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid.at(i);
    }

    vector<vector<int>> visited(r + 1, vector<int>(c + 1, -1));
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    visited.at(sy).at(sx) = 0;

    vector<int> dy = { 1, -1, 0,  0 };
    vector<int> dx = { 0, 0,  1, -1 };

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        if (pos.first == gy && pos.second == gx) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (grid.at(pos.first - 1 + dy.at(i)).at(pos.second - 1 + dx.at(i)) == '.'
                && visited.at(pos.first + dy.at(i)).at(pos.second + dx.at(i)) == -1) {
                visited.at(pos.first + dy.at(i)).at(pos.second + dx.at(i)) = visited.at(pos.first).at(pos.second) + 1;
                q.push({ pos.first + dy.at(i), pos.second + dx.at(i) });
            }
        }
    }

    cout << visited.at(gy).at(gx) << endl;
}

/* ===== 改善点 =====
   1. grid は 0 始まり、visited と座標は 1 始まりで、30 行目だけ - 1 してそろえている（最初の RE もこのずれ）。
      読んだ直後に座標を 0 始まりにそろえれば、visited も r × c で作れて、30 行目の - 1 もいらない（6・13・30 行目）

    sy--; sx--; gy--; gx--;                            // 6 行目のあと
    vector<vector<int>> dist(r, vector<int>(c, -1));   // 13 行目（中身は距離なので名前は dist）

   2. 行き先のマスが 4 回ずつ出てくるので、先に変数に入れる（30–33 行目）

            int ny = pos.first + dy.at(i);             // 30–33 行目
            int nx = pos.second + dx.at(i);
            if (grid.at(ny).at(nx) == '.' && dist.at(ny).at(nx) == -1) {
                dist.at(ny).at(nx) = dist.at(pos.first).at(pos.second) + 1;
                q.push({ ny, nx });
            }
*/
