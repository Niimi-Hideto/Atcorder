#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        int tmp = s.at(i) - '0';
        int num = tmp % 10;

        ans++;
        ans += (num - cnt + 10) % 10;
        cnt = ((num - cnt + 10) % 10 + cnt) % 10;
    }
    cout << ans << endl;
}

/* 改善点（変わる行だけ）

// 10〜11行目：s.at(i) - '0' は最初から 0〜9 なので % 10 はいらない
        int num = s.at(i) - '0';

// 15行目：cnt は「今までに B を押した回数 % 10」。14行目で num に合わせるぶん押し足したので、押したあとはちょうど num
        cnt = num;
*/
