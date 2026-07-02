#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans_num = 0;
    int tmp_num = 0;
    vector<string> ans;
    vector<string> vec;

    for (int i = 0; i < n - k + 1; i++) {
        string tmp = "";
        tmp = s.substr(i, k);
        vec.push_back(tmp);
    }

    for (int i = 0; i < n - k + 1; i++) {
        string tmp = "";
        tmp = s.substr(i, k);
        tmp_num = count(vec.begin(), vec.end(), tmp);
        ans_num = max(ans_num, tmp_num);
    }

    for (int i = 0; i < n - k + 1; i++) {
        string tmp = "";
        tmp = s.substr(i, k);

        tmp_num = count(vec.begin(), vec.end(), tmp);
        if (tmp_num == ans_num) {
            ans.push_back(tmp);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans_num << endl;
    string flag = "";
    for (string x : ans) {
        if (flag != x) {
            cout << x << " ";
        }
        flag = x;
    }
    cout << endl;
}

// 【改善版】
// 1. string tmp = s.substr(i, k); と1行にまとめる（= "" の初期化不要）
// 2. ループ2・3は vec を使い回す（s.substr を再計算しない）
//
// for (string t : vec) {
//     tmp_num = count(vec.begin(), vec.end(), t);
//     ans_num = max(ans_num, tmp_num);
// }
// for (string t : vec) {
//     tmp_num = count(vec.begin(), vec.end(), t);
//     if (tmp_num == ans_num) ans.push_back(t);
// }
