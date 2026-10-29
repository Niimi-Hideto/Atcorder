#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> c(h + 1);
    for (int i = 1; i <= h; i++) {
        cin >> c.at(i);
        c.at(i) = " " + c.at(i);
    }

    /* 自分で書いたもの（毎回「今いちばん白が多い行か列」を1本ずつ選んで塗っていた。
       行と列は交わるので、先に選んだ1本であとの得が変わり、いちばん多くなるとは限らない）
    for (int query = 0; query < k; query++) {
        int ro = 0, mx = 0;
        for (int i = 1; i <= h; i++) {
            int cnt = 0;
            for (int j = 1; j <= w; j++) {
                if (c.at(i).at(j) == '.') {
                    cnt++;
                }
            }
            if (mx < cnt) {
                mx = cnt;
                ro = i;
            }
        }

        int co = 0;
        for (int j = 1; j <= w; j++) {
            int cnt = 0;
            for (int i = 1; i <= h; i++) {
                if (c.at(i).at(j) == '.') {
                    cnt++;
                }
            }
            if (mx < cnt) {
                mx = cnt;
                co = j;

                ro = -1;
            }
        }

        if (ro != -1) {
            for (int j = 1; j <= w; j++) {
                c.at(ro).at(j) = '#';
            }
        }
        else {
            for (int i = 1; i <= h; i++) {
                c.at(i).at(co) = '#';
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (c.at(i).at(j) == '#') {
                ans++;
            }
        }
    }
    cout << ans << endl;
    */

    int ans = 0;
    // 塗る行の選び方を全部試す（行 i を塗るなら t の i - 1 桁目が 1）。2^10 = 1024 通り
    for (int t = 0; t < (1 << h); t++) {
        vector<string> d = c;  // 行を塗ったあとのマス目（元の c は次の t でも使うのでコピー）
        int rest = k;          // 列に使える残りの回数

        for (int i = 1; i <= h; i++) {
            if (((t >> (i - 1)) & 1) == 0) continue;
            rest--;
            for (int j = 1; j <= w; j++) {
                d.at(i).at(j) = '#';
            }
        }
        // 行だけで K 回を超えた選び方はできないので飛ばす
        if (rest < 0) continue;

        // 列どうしは交わらないので、白の多い列から rest 本塗るのが一番いい
        vector<int> white(w + 1);  // white[j]：行を塗ったあと、列 j に残っている白の数
        int black = 0;             // 行を塗ったあとの黒の数
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (d.at(i).at(j) == '.') {
                    white.at(j)++;
                }
                else {
                    black++;
                }
            }
        }
        sort(white.rbegin(), white.rend());  // 白の多い順（添字 0 のダミーの 0 は一番後ろへ行く）
        for (int x = 0; x < rest; x++) {
            black += white.at(x);  // その列を塗ると、残っていた白が全部黒になる
        }

        ans = max(ans, black);
    }
    cout << ans << endl;
}
