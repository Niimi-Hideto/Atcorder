#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);

    for (int i = 0; i < h; i++) {
        cin >> s.at(i);
    }

    vector<vector<bool>> visited(h, vector<bool>(w));
    vector<int> di = { 0, 1, 0, -1 };
    vector<int> dj = { 1, 0, -1, 0 };
    int ans = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s.at(i).at(j) == '.' && visited.at(i).at(j) == false) {
                visited.at(i).at(j) = true;
                queue<pair<int, int>> q;
                q.push({ i, j });
                bool ok = true;

                while (q.size() > 0) {
                    pair<int, int> tmp = q.front();
                    q.pop();
                    int si = tmp.first;
                    int sj = tmp.second;
                    if (si == 0 || si == h - 1 || sj == 0 || sj == w - 1) {
                        ok = false;
                    }
                    for (int k = 0; k < 4; k++) {
                        if (si + di.at(k) == -1 || si + di.at(k) == h
                            || sj + dj.at(k) == -1 || sj + dj.at(k) == w) {
                            continue;
                        }
                        if (s.at(si + di.at(k)).at(sj + dj.at(k)) == '.'
                            && visited.at(si + di.at(k)).at(sj + dj.at(k)) == false) {
                            visited.at(si + di.at(k)).at(sj + dj.at(k)) = true;
                            q.push({ si + di.at(k), sj + dj.at(k) });
                        }
                    }
                }
                if (ok) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
