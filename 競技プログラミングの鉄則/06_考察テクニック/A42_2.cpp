#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> ab(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ab.at(i).first >> ab.at(i).second;
    }
    sort(ab.begin() + 1, ab.end());

    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i > j) {
            j = i;
        }
        while (j < n) {
            if (ab.at(j + 1).first - ab.at(i).first <= k) {
                j++;
            }
            else {
                break;
            }
        }

        int cnt = 0;
        vector<int> tmp(1, 0);
        for (int x = i; x <= j; x++) {
            tmp.push_back(ab.at(x).second);
        }
        sort(tmp.begin() + 1, tmp.end());

        int m = 0;
        for (int l = 1; l <= (int)tmp.size(); l++) {
            if (l > m) {
                m = l;
            }
            while (m < (int)tmp.size() - 1) {
                if (tmp.at(m + 1) - tmp.at(l) <= k) {
                    m++;
                }
                else {
                    break;
                }
            }
            cnt = max(cnt, m - l + 1);
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

/* ===== 改善点 =====
   1. tmp は自分で作る入れ物なので、入力の番号にそろえる先頭の 0 はいらない。
      空から始めて 0 番から使えば、最後の添字が tmp.size() - 1 になる、と素直に書ける（30・34・37 行目）
      37 行目の l <= tmp.size() は 1 回多く回っていた（たまたま答えに影響しなかっただけ）

        vector<int> tmp;                               // 30 行目
        sort(tmp.begin(), tmp.end());                  // 34 行目
        for (int l = 0; l < (int)tmp.size(); l++) {    // 37 行目

   2. 36 行目で最初は入力と同じ k を使っていた（3 回目）。範囲の端は役割で l・r と名付け、
      3 重目のループ変数は入力に使わない x・y にする

   3. 本の解き方：体力・気力は 1〜100 と小さいので、左下の角 (a, b) を値で全部試し、毎回 N 人を数える。
      100 × 100 × N ≈ 3×10^6 で間に合い、ソートも範囲を伸ばす処理もいらない（13–51 行目）。
      今回のミスはどれも「ソートして伸ばす」部分で出ていたので、値の範囲が小さいときはこちらが楽。
      自分の形は、値が 10^9 のように大きくても使える

    int ans = 0;                                       // 13–51 行目
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            int cnt = 0;
            for (int x = 1; x <= n; x++) {
                if (a <= ab.at(x).first && ab.at(x).first <= a + k && b <= ab.at(x).second && ab.at(x).second <= b + k) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
*/
