#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    int mx = 1;
    for (int i = 1; i <= k; i++) {
        mx *= n;
    }

    vector<string> ans;
    for (int i = 0; i < mx; i++) {
        int num = i;
        string tmp;
        for (int j = 0; j < k; j++) {
            tmp += s.at((num % n));
            num /= n;
        }

        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());
    cout << ans.at(x - 1) << endl;
}

/* 改善点（変わる行だけ）

// ① 変数名を中身に合わせる
//    mx は最大値ではなく「数列が全部で何通りか」→ total、ans は答えではなく「全部の文字列」→ strs
    int total = 1;
        total *= n;
    vector<string> strs;
    for (int i = 0; i < total; i++) {
        strs.push_back(tmp);
    sort(strs.begin(), strs.end());
    cout << strs.at(x - 1) << endl;

// ② 23行目：かっこが1組多い
            tmp += s.at(num % n);
*/