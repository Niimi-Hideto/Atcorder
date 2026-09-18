#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if ((int)a.size() == 0) {
            a.push_back({ tmp, 1 });
            continue;
        }

        if (a.back().first == tmp) {
            a.back().second++;
            if (a.back().second == 4) {
                a.pop_back();
            }
        }
        else {
            a.push_back({ tmp, 1 });
        }
    }
    int ans = 0;
    for (pair<int, int> x : a) {
        ans += x.second;
    }
    cout << ans << endl;
}

/* ===== 改善版（今の知識範囲での書き方）=====

   直した点
   1. 空チェックを独立したブロックにせず、&& の短絡評価で1つの if にまとめる。
      元のコードは push_back({tmp, 1}) が2箇所にあり、片方だけ直して壊す元になる
      （ABC474 Bで端数処理が2箇所に分裂して事故ったのと同じ構図）。
      !blocks.empty() を必ず左に書くこと。&&は左から評価されるので、
      空のときは blocks.back() まで到達しない（逆順にすると空でback()を呼んで壊れる）。
   2. (int)a.size() == 0 → a.empty()。意図が直接読めるしキャストも要らない
   3. 変数名を blocks に。中身は元の数列ではなく (値, 連続数) の塊なので
   4. 範囲forは const auto& で受けるのが定番

int main() {
    int n;
    cin >> n;

    // blocks = 残っている列を「(値, 連続数)」の塊にまとめたもの。
    // 連続数が4になった塊は消えるので、中に残る連続数は必ず1〜3。
    vector<pair<int, int>> blocks;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        // 境界チェック(!empty)を必ず左に置く
        if (!blocks.empty() && blocks.back().first == tmp) {
            blocks.back().second++;
            if (blocks.back().second == 4) {
                blocks.pop_back();
            }
        }
        else {
            blocks.push_back({ tmp, 1 });
        }
    }

    // 増減させず最後に数える（pop_backのときに-4を忘れる事故が起きない）
    int ans = 0;
    for (const auto& x : blocks) {
        ans += x.second;
    }
    cout << ans << endl;
}

===== ここまで ===== */
