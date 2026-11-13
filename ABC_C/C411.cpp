#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int ans = 0;
    vector<bool> grid(n + 1);
    for (int i = 1; i <= q; i++) {
        int a;
        cin >> a;

        if (!grid.at(a)) {
            if (a == 1 && n >= 2) {
                if (!grid.at(a + 1)) {
                    ans++;
                }
            }
            else if (a == n) {
                if (!grid.at(a - 1)) {
                    ans++;
                }
            }
            else {
                if (grid.at(a - 1) && grid.at(a + 1)) {
                    ans--;
                }
                else if (!grid.at(a - 1) && !grid.at(a + 1)) {
                    ans++;
                }
            }
            grid.at(a) = true;
        }
        else {
            if (a == 1 && n >= 2) {
                if (!grid.at(a + 1)) {
                    ans--;
                }
            }
            else if (a == n) {
                if (!grid.at(a - 1)) {
                    ans--;
                }
            }
            else {
                if (grid.at(a - 1) && grid.at(a + 1)) {
                    ans++;
                }
                else if (!grid.at(a - 1) && !grid.at(a + 1)) {
                    ans--;
                }
            }
            grid.at(a) = false;
        }

        cout << ans << endl;
    }
}

/* 改善点（変わる行だけ）

// ① 両端に「ずっと白」のマス（0 番目と n + 1 番目）を足すと、a = 1・a = N の場合分けがいらない
    vector<bool> grid(n + 2);

// 14〜55行目：端の分岐を消して、真ん中の処理だけにする
        if (!grid.at(a)) {
            if (grid.at(a - 1) && grid.at(a + 1)) {
                ans--;
            }
            else if (!grid.at(a - 1) && !grid.at(a + 1)) {
                ans++;
            }
            grid.at(a) = true;
        }
        else {
            if (grid.at(a - 1) && grid.at(a + 1)) {
                ans++;
            }
            else if (!grid.at(a - 1) && !grid.at(a + 1)) {
                ans--;
            }
            grid.at(a) = false;
        }

// ② さらにまとめるなら：両隣の黒の数 k で、白→黒は 1 − k 増える、黒→白は 1 − k 減る
        int k = grid.at(a - 1) + grid.at(a + 1);
        if (!grid.at(a)) {
            ans += 1 - k;
        }
        else {
            ans -= 1 - k;
        }
        grid.at(a) = !grid.at(a);
*/
