#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int sizes = (int)s.size();
    int sizet = (int)t.size();

    s = "?" + s;
    t = "#" + t;

    vector<vector<int>> dp(sizes + 1, vector<int>(sizet + 1));
    for (int i = 1; i <= sizes; i++) {
        for (int j = 1; j <= sizet; j++) {

            int tmp;
            ((s.at(i) == t.at(j)) ? tmp = 1 : tmp = 0);
            dp.at(i).at(j) = max({ dp.at(i - 1).at(j), dp.at(i).at(j - 1), dp.at(i - 1).at(j - 1) + tmp });
        }
    }
    cout << dp.at(sizes).at(sizet) << endl;
}

/* ===== 改善点 =====
   1. ?: は「値を選ぶ」書き方なので、中で代入せず、選んだ値を変数に入れる形にする（17〜18 行目）。
      中身は「同じ文字なら 1」なので名前は same などにする

   int same = (s.at(i) == t.at(j)) ? 1 : 0;
   dp.at(i).at(j) = max({ dp.at(i - 1).at(j), dp.at(i).at(j - 1), dp.at(i - 1).at(j - 1) + same });
*/
