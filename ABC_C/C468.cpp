#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    /* 自分で書いたもの（P・Q を int 1 つで受け取ろうとしていたが、vector のまま持てば < で辞書順に比べられる）
    int p, q;
    for (int i = n; i >= 1; i--) {
        int tmp;
        cin >> tmp;


    }
    */

    // P と Q は vector のまま持つ（vector どうしは < > で辞書順に比べられる）
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> q.at(i);
    }

    // 一番小さい並び (1, 2, …, N) から始める
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v.at(i) = i + 1;
    }

    int cnt = 0;
    // 全部の並び替えを辞書順に 1 つずつ見る（N! ≤ 3.6×10^6 通り）
    do {
        // P より大きく、Q より小さいなら数える
        if (v > p && v < q) {
            cnt++;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << cnt << endl;
}
