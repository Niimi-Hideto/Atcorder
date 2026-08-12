#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    int cnt = 1;
    long long tmp = vec.at(0);
    vector<long long> ans;
    for (int i = 1; i < n; i++) {
        if (tmp != vec.at(i)) {
            ans.push_back(cnt * tmp);
            tmp = vec.at(i);
            cnt = 1;
        }
        else {
            cnt++;
        }

        if (i == n - 1 && tmp == vec.at(i)) {
            ans.push_back(cnt * tmp);
        }
    }

    int size = (int)ans.size();
    sort(ans.rbegin(), ans.rend());

    long long a = 0;
    for (int i = k; i < size; i++) {
        a += ans.at(i);
    }
    cout << a << endl;
}

// 改善点: 最後のグループのpushは、ループ内で毎回i==n-1を判定せず
// ループの外に出して無条件に1回だけpushすれば同じ動きになる
// （N=1のとき今のコードだとansが空になるが、下の形なら自動的に正しく処理される）
//
// int cnt = 1;
// long long tmp = vec.at(0);
// vector<long long> ans;
// for (int i = 1; i < n; i++) {
//     if (tmp != vec.at(i)) {
//         ans.push_back(cnt * tmp);
//         tmp = vec.at(i);
//         cnt = 1;
//     }
//     else {
//         cnt++;
//     }
// }
// ans.push_back(cnt * tmp);  // ループを抜けた時点で残ってる最後のグループ
