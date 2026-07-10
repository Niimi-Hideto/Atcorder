#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s.at(i);

    int ans = 0;

    // 長方形の上下・左右の端を4重ループで全列挙（0-indexed）
    for (int h1 = 0; h1 < h; h1++) {
        for (int h2 = h1; h2 < h; h2++) {
            for (int w1 = 0; w1 < w; w1++) {
                for (int w2 = w1; w2 < w; w2++) {

                    // この長方形が点対称かチェック
                    bool ok = true;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            // 対称点は (h1+h2-i, w1+w2-j)
                            if (s.at(i).at(j) != s.at(h1 + h2 - i).at(w1 + w2 - j)) {
                                ok = false;
                            }
                        }
                    }
                    if (ok) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
