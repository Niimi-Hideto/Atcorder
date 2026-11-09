#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s.at(i);
    }

    /* 自分で書いたもの（K によってループを何重にするかが変わるので、for を入れ子にしていく形では書けない。
       また、内側のループ変数も i で外側と同じ名前になっていた）
    vector<string> dictionary;
    for (int i = 1; i <= n; i++) {
        if (k >= 2) {
            for (int i = 1; i <= n; i++) {

            }
        }
    }
    */

    // 数列の個数 N^K を作る（pow は double を返すので掛け算で）
    int total = 1;
    for (int i = 0; i < k; i++) {
        total *= n;
    }

    vector<string> dictionary;
    // t = 0 〜 N^K − 1 を K 桁の N 進数とみなすと、各桁が「S の何番目を使うか」になる
    for (int t = 0; t < total; t++) {
        string str = "";
        int tmp = t;
        for (int i = 0; i < k; i++) {
            int d = tmp % n;   // 一番下の桁（0 〜 N − 1）
            tmp /= n;          // 1 桁ずらす
            str += s.at(d + 1);  // s は 1 始まりなので d + 1 番目
        }
        dictionary.push_back(str);
    }

    // 辞書順に並べて、小さいほうから X 番目（0 始まりなので X − 1）
    sort(dictionary.begin(), dictionary.end());
    cout << dictionary.at(x - 1) << endl;
}
