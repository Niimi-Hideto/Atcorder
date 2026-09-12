#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<pair<char, int>> num;
    for (int i = 0; i < (int)s.size(); i++) {
        char tmp = s.at(i);
        if (i != 0 && num.back().first == tmp) {
            num.back().second++;
        }
        else {
            num.push_back({ tmp, 1 });
        }
    }

    long long ans = 0;
    for (int i = 1; i < (int)num.size(); i++) {
        if ((num.at(i).first - '0') == (num.at(i - 1).first - '0') + 1) {
            ans += min(num.at(i).second, num.at(i - 1).second);
        }
    }

    cout << ans << endl;
}

// 改善案：
// ①11行目の `i != 0` は `!num.empty()` の方が意図が直接的。
//   num.back() を呼ぶ前提は「numが空でないこと」なので、それをそのまま書く。
//   i != 0 は「たまたま同じ条件になっている」形で、ループ構造を変えると壊れやすい
//
//     if (!num.empty() && num.back().first == tmp) {
//
// ②21行目の `- '0'` は両辺で打ち消されるので不要（数字の文字コードは連続しているため）
//
//     if (num.at(i).first == num.at(i - 1).first + 1) {
//
//   - '0' が必要なのは「文字を数値として使う」とき（計算に使う・配列の添字にする）。
//   大小や連続を比較するだけなら不要。
//   なお char + 1 の結果は int になるので、出力するときだけ (char) へのキャストが必要
//   （cout << c + 1 は数値が出る。06-29の「char + char は文字コードの足し算」と同じ話）
