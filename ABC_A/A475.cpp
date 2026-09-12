#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans;
    for (int i = 0; i < s.size(); i++) {
        ans += s.at(i);
        if (i == s.size() - 1) {
            continue;
        }
        ans += 'o';
    }
    cout << ans << endl;
}

// 改善案：「最後だけスキップ」をcontinueで書くより、条件を反転してifで包む方が素直
//   （continueは「この先を飛ばす」意図なので、「条件を満たすときだけ足す」場面ではifが読みやすい）
//
//     for (int i = 0; i < (int)s.size(); i++) {
//         ans += s.at(i);
//         if (i < (int)s.size() - 1) {   // 最後以外なら 'o' を足す
//             ans += 'o';
//         }
//     }
