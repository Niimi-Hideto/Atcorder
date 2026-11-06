#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    /* 自分で書いたもの（1 等の券があればそれを出して終わる形は考え方として正しいが、
       s を int で読んでいるので、0012 のような番号は 12 と出てしまう。
       2 等・3 等の券を分けて持つ形から、全探索のところで止まっていた）
    vector<int> two, three;
    for (int i = 1; i <= n; i++) {
        int s, t;
        cin >> s >> t;

        if (t == 1) {
            cout << s << endl;
            return 0;
        }
        else if (t == 2) {
            two.push_back(s);
        }
        else {
            three.push_back(s);
        }
    }

    for (int num = 0; num < 10000; num++) {

    }
    */

    // 番号は 0012 のように頭に 0 があるので、string で読む
    vector<string> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i) >> t.at(i);
    }

    int cnt = 0;     // 当選番号としてあり得る候補の数
    string ans;      // あり得る候補（1 個だけなら、これが答え）

    // 候補 0000 〜 9999 を全部試す
    for (int x = 0; x < 10000; x++) {
        // x を頭に 0 を付けた 4 桁の文字列にする（12 → "0012"）
        string cand = to_string(x);
        while (cand.size() < 4) {
            cand = "0" + cand;
        }

        // N 枚全部と矛盾しないか確かめる
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int d = 0;  // cand と s[i] で違う桁の数
            for (int k = 0; k < 4; k++) {
                if (cand.at(k) != s.at(i).at(k)) d++;
            }

            // 1 等なら 0 桁違い、2 等なら 1 桁違い、3 等なら 2 桁以上違い、でないと矛盾
            if (t.at(i) == 1 && d != 0) ok = false;
            if (t.at(i) == 2 && d != 1) ok = false;
            if (t.at(i) == 3 && d < 2) ok = false;
        }

        if (ok) {
            cnt++;
            ans = cand;
        }
    }

    // あり得る候補が 1 個だけなら答え、2 個以上なら決まらない
    if (cnt == 1) {
        cout << ans << endl;
    }
    else {
        cout << "Can't Solve" << endl;
    }
}
