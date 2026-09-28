#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int size_s = (int)s.size();
    int size_t = (int)t.size();

    vector<vector<int>> dp(size_s + 1, vector<int>(size_t + 1, 0));
    dp.at(0).at(0) = 0;
    for (int i = 0; i <= size_s; i++) {
        for (int j = 0; j <= size_t; j++) {
            if (i == 0) {
                if (j == 0) continue;
                dp.at(i).at(j) = dp.at(i).at(j - 1) + 1;
            }
            else if (j == 0) {
                dp.at(i).at(j) = dp.at(i - 1).at(j) + 1;
            }
            else {
                if (s.at(i - 1) != t.at(j - 1)) {
                    dp.at(i).at(j) = min({ dp.at(i - 1).at(j), dp.at(i).at(j - 1), dp.at(i - 1).at(j - 1) }) + 1;
                }
                else {
                    dp.at(i).at(j) = min({ dp.at(i - 1).at(j) + 1, dp.at(i).at(j - 1) + 1, dp.at(i - 1).at(j - 1) });
                }
            }
        }
    }

    cout << dp.at(size_s).at(size_t) << endl;
}

/* ===== 改善点 =====
   1. size_t は C++ にもともとある型の名前（s.size() が返す型）なので、変数名に使うと型が隠れる。
      同じ範囲で size_t を型として使うとエラーになる。len_s / len_t などにする
      （変数名 time が std::time と被るのと同じ種類の話）
   2. 24行目と27行目は3つの操作（削除 +1 / 挿入 +1 / 変更 +cost）を書いているだけで、
      違うのは変更のコストだけ。そこを変数にすれば1つの式で書ける

   int cost = (s.at(i - 1) == t.at(j - 1)) ? 0 : 1;
   dp.at(i).at(j) = min({ dp.at(i - 1).at(j) + 1,        // S の文字を削除
                          dp.at(i).at(j - 1) + 1,        // T の文字を挿入
                          dp.at(i - 1).at(j - 1) + cost  // 変更（同じ文字なら 0）
                        });
*/
