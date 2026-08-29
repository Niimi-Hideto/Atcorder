//解けなかった．

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int i = 0, j = 0; // sを読んでる位置、tを読んでる位置
    int ans = 0;
    bool ok = true;

    // sとtの両方を読み終わるまで続ける
    while (i < (int)s.size() || j < (int)t.size()) {
        // sの現在位置から連続する'A'の個数を数える（骨格の直前にあるA）
        int cnt_s = 0;
        while (i < (int)s.size() && s.at(i) == 'A') {
            cnt_s++;
            i++;
        }
        // tの現在位置から連続する'A'の個数を数える
        int cnt_t = 0;
        while (j < (int)t.size() && t.at(j) == 'A') {
            cnt_t++;
            j++;
        }
        // Aは挿入・削除が自由にできるので、個数の差分だけ操作すればいい
        // （多い方から削るか、少ない方に足すか。どちらもコストは1操作=1個）
        ans += abs(cnt_s - cnt_t);

        // Aを読み飛ばした後、両方に非A文字が残っているなら、それは「骨格」の文字
        if (i < (int)s.size() && j < (int)t.size()) {
            // 骨格の文字はA以外なので、削除も挿入もできない→一致してないと詰む
            if (s.at(i) != t.at(j)) {
                ok = false;
                break;
            }
            i++;
            j++;
        }
        // 片方だけ非A文字が余っている（もう片方は文字列の末尾）
        else if (i < (int)s.size() || j < (int)t.size()) {
            // 余った非A文字は消すことも埋めることもできないので不可能
            ok = false;
            break;
        }
        // 両方とも末尾に到達していれば、このifたちを素通りしてループ条件でloop終了
    }

    cout << (ok ? ans : -1) << endl;
}
