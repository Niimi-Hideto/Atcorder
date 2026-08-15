#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> hw(h);
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        cin >> hw.at(i);
    }

    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (hw.at(i).at(j) == '.' && !visited.at(i).at(j)) {
                queue<pair<int, int>> que;
                que.push({i, j});
                visited.at(i).at(j) = true;
                bool touched_edge = false;

                while (!que.empty()) {
                    pair<int, int> cur = que.front();
                    que.pop();
                    int ci = cur.first;
                    int cj = cur.second;

                    if (ci == 0 || ci == h - 1 || cj == 0 || cj == w - 1) {
                        touched_edge = true;
                    }

                    for (int d = 0; d < 4; d++) {
                        int ni = ci + di.at(d);
                        int nj = cj + dj.at(d);
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w && hw.at(ni).at(nj) == '.' && !visited.at(ni).at(nj)) {
                            visited.at(ni).at(nj) = true;
                            que.push({ni, nj});
                        }
                    }
                }

                if (!touched_edge) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
