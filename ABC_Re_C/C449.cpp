#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    // cnt.at(c).at(k) = 文字cが S の先頭k文字（S[0]〜S[k-1]）に何個あるか
    // k=0 の行はあえて全部0にしておく「番兵」。これがあると i-1 が0未満になる心配がなくなる
    vector<vector<int>> cnt(26, vector<int>(n + 1, 0));
    for (int k = 1; k <= n; k++) {
        for (int c = 0; c < 26; c++) {
            cnt.at(c).at(k) = cnt.at(c).at(k - 1); // 前の状態をコピー
        }
        cnt.at(s.at(k - 1) - 'a').at(k)++; // 今読んだ文字だけ+1
    }

    long long ans = 0; // N*Rの掛け算でintを超えるのでlong long
    // j を1-indexedの後ろ側の添字として1〜Nまで見る
    for (int j = 1; j <= n; j++) {
        int c = s.at(j - 1) - 'a';
        int hi = j - l;              // i の上限（1-indexed）
        int lo = max(1, j - r);      // i の下限。1未満にならないようclamp
        if (hi < lo) continue;       // 条件を満たすiが1つも無い

        // 区間[lo, hi]（1-indexed）にcが何個あるか = cnt[hi] - cnt[lo-1]
        // cnt[k]は「先頭k文字」なので、位置lo(1-indexed)を含めたいならcnt[lo-1]を引く
        ans += cnt.at(c).at(hi) - cnt.at(c).at(lo - 1);
    }

    cout << ans << endl;
}
