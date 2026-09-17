#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }

    // last.at(v) = 値vが最後に操作された時刻（1〜q）。0なら一度も操作されていない。
    // 同じ値が何度来ても上書きされるので、最後の時刻だけが残る。
    vector<int> a(q);
    vector<int> last(n + 1, 0);
    for (int i = 0; i < q; i++) {
        cin >> a.at(i);
        last.at(a.at(i)) = i + 1;
    }

    vector<int> ans;

    // ① 一度も操作されなかった値を、元のPの順に。
    //    Pを先頭から見ているので相対順序はそのまま保たれる。
    for (int i = 0; i < n; i++) {
        if (last.at(p.at(i)) == 0) {
            ans.push_back(p.at(i));
        }
    }

    // ② 操作された値を、最後の操作が早い順に。
    //    aを先頭から辿るので時刻の昇順に出てくる＝ソート不要。
    //    lastと一致するのは最後の1回だけなので重複もしない。
    for (int i = 0; i < q; i++) {
        if (last.at(a.at(i)) == i + 1) {
            ans.push_back(a.at(i));
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans.at(i) << (i == n - 1 ? "\n" : " ");
    }
}
