#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（途中）=====
   ・左から高さを決めて、マイナスになったらさかのぼって足し直す形にしたため、直した所がまた別の条件とぶつかり場合分けが増える
   ・17・21 行目 h.at(i + 1) = h.at(i)++; は「h.at(i) の今の値を入れてから h.at(i) を 1 増やす」意味になる
   ・28 行目 s.at(i + 1) は i = n − 2 のとき範囲外。出力もない

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> h(n + 1, 1);

    int i = 0;
    int last_a = 0, last_b = 0;
    bool mai = false;
    while (i < n - 1) {
        if (s.at(i) == 'A') {
            last_a = i;
            h.at(i + 1) = h.at(i)++;
        }
        else {
            last_b = i;
            h.at(i + 1) = h.at(i)--;

            if (h.at(i + 1) < 0) {
                mai = true;
            }
        }

        if (mai && i == (int)s.size() || s.at(i + 1) == 'A') {
            for (int j = last_a; j <= i; j++) {
                h.at(j) += abs(h.at(i)) + 1;
            }
            mai = false;
        }
        i++;
    }
}
*/

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 草は 0〜n−1 番。s.at(i) は草 i と草 i + 1 の関係
    // left.at(i)：左側の条件（'A' ＝ 右が高い）だけを守るときの、草 i の高さの最小
    //   左隣より高くないといけない（s.at(i − 1) == 'A'）なら左隣 + 1、そうでなければ 1
    vector<int> left(n, 1);
    for (int i = 1; i < n; i++) {
        if (s.at(i - 1) == 'A') {
            left.at(i) = left.at(i - 1) + 1;
        }
    }

    // right.at(i)：右側の条件（'B' ＝ 右が低い）だけを守るときの、草 i の高さの最小
    //   右隣より高くないといけない（s.at(i) == 'B'）なら右隣 + 1、そうでなければ 1
    vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (s.at(i) == 'B') {
            right.at(i) = right.at(i + 1) + 1;
        }
    }

    // 草 i は左右どちらの条件も守る必要があるので、2 つの下限の大きいほう
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(left.at(i), right.at(i));
    }
    cout << ans << endl;
}
