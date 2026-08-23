//TLEして終了．D問題の精進が始まったらまた解いてみる．

#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s.at(i);
    }

    vector<bool> yoko_bomb(h, false);
    for (int i = 0; i < h; i++) {
        if (count(s.at(i).begin(), s.at(i).end(), '#') > 0) {
            yoko_bomb.at(i) = true;
        }
    }

    vector<bool> tate_bomb(w, false);
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (s.at(i).at(j) == '#') {
                tate_bomb.at(j) = true;
                break;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s.at(i).at(j) == '.' && (yoko_bomb.at(i) || tate_bomb.at(j))) {
                s.at(i).at(j) = 'o';
            }
        }
    }

    int ans = 0;
    vector<int> di = { -1, 1, 0, 0 };
    vector<int> dj = { 0, 0, -1, 1 };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            vector<vector<bool>> visited(h, vector<bool>(w));
            queue<tuple<int, int, int>> que;
            if (s.at(i).at(j) == '.') {
                ans++;
            }
            else if (s.at(i).at(j) == 'o') {
                que.push({ i, j, 0 });
                visited.at(i).at(j) = true;
                bool ok = false;
                while (!que.empty()) {
                    tuple<int, int, int> cur = que.front();
                    que.pop();
                    int ci = get<0>(cur);
                    int cj = get<1>(cur);
                    int ccnt = get<2>(cur);

                    for (int d = 0; d < 4; d++) {
                        int ni = ci + di.at(d);
                        int nj = cj + dj.at(d);
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w &&
                            s.at(ni).at(nj) == '.' && ccnt <= k - 1) {
                            ok = true;
                        }
                        else if (ni >= 0 && ni < h && nj >= 0 && nj < w &&
                            s.at(ni).at(nj) == 'o' && !visited.at(ni).at(nj) &&
                            ccnt <= k - 1) {
                            visited.at(ni).at(nj) = true;
                            que.push({ ni, nj, (ccnt + 1) });
                        }
                    }
                    if (ok == true) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
