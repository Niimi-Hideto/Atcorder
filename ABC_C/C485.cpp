#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c.at(i);
    }

    bool ok = true;
    vector<int> ans(n, 10000000);
    int j = 1;
    for (int i = 0; i < n - 1; i++) {
        if (ok) {
            while (c.at(i) == c.at(j)) {
                j++;
                if (j == n - 1) {
                    ok = false;
                    break;
                }
            }
            ans.at(i) = j - i;
        }
        else {
            if (c.at(i) != c.at(j)) {
                ans.at(i) = j - i;
            }
        }
    }

    ok = true;
    j = n - 2;
    for (int i = n - 1; i > 0; i--) {
        if (ok) {
            while (c.at(i) == c.at(j)) {
                j--;
                if (j == 0) {
                    ok = false;
                    break;
                }
            }
            ans.at(i) = min(ans.at(i), i - j);
        }
        else {
            if (c.at(i) != c.at(j)) {
                ans.at(i) = min(ans.at(i), i - j);
            }
        }
    }

    for (int i = 0; i < n;i++) {
        cout << ans.at(i);
        if (i != n - 1) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }
}

/* 改善点（変わる行だけ）

// ② 14行目：10000000 に名前を付ける（0を数えないと意味が分からないので）
    const int INF = 1000000000;
    vector<int> ans(n, INF);

// ① 13・15〜52行目（ok・j と2つの for）を、「1つ前の点の答え」を使う形にする。while と ok がいらなくなる
//    ・左側：点 i と点 i − 1 の色が違えば 1。同じなら、左で一番近い違う色は点 i − 1 と同じ点なので「点 i − 1 の答え + 1」
//    ・右側：同じ考え方を i = n − 2 から逆向きに。右側だけの距離を d で持ち、左側の答えと min を取る
//    （今のコードは 20行目で break したとき c.at(n - 1) の色を確かめずに 25行目で答えを入れていて、
//     右から回したときに「左隣が違う色なので 1」で上書きされるから、たまたま正しくなっている）
    for (int i = 1; i < n; i++) {
        if (c.at(i) != c.at(i - 1)) ans.at(i) = 1;
        else ans.at(i) = ans.at(i - 1) + 1;
    }

    int d = INF;
    for (int i = n - 2; i >= 0; i--) {
        if (c.at(i) != c.at(i + 1)) d = 1;
        else d++;
        ans.at(i) = min(ans.at(i), d);
    }
*/
