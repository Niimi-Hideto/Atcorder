#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
    }


    {
        bool ok = true;
        bool ans = true;
        int tmp = -1;
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (ok) {
                if (a.at(i) != b.at(i)) {
                    ok = false;
                    tmp = b.at(i);
                }
                else {
                    continue;
                }
            }

            if (i == n - 1) {
                if (ok) {
                    break;
                }
                else {
                    if (a.at(n - 1) != tmp) {
                        ans = false;
                        break;
                    }
                    break;
                }
            }
            if (a.at(i) != b.at(i + 1)) {
                if (a.at(i) != tmp) {
                    ans = false;
                }
                else {
                    j = i + 1;
                    break;
                }
            }
        }

        if (j != -1) {
            for (int i = j; i < n; i++) {
                if (a.at(i) != b.at(i)) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    {
        bool ok = true;
        bool ans = true;
        int tmp = -1;
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (ok) {
                if (a.at(i) != b.at(i)) {
                    ok = false;
                    tmp = a.at(i);
                }
                else {
                    continue;
                }
            }

            if (i == n - 1) {
                if (ok) {
                    break;
                }
                else {
                    if (b.at(n - 1) != tmp) {
                        ans = false;
                        break;
                    }
                    break;
                }
            }
            if (a.at(i + 1) != b.at(i)) {
                if (b.at(i) != tmp) {
                    ans = false;
                }
                else {
                    j = i + 1;
                    break;
                }
            }
        }

        if (j != -1) {
            for (int i = j; i < n; i++) {
                if (a.at(i) != b.at(i)) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}

/* 改善点（変わる行だけ）

// ① 17〜69行目と71〜123行目は、a と b の役割を入れ替えただけの同じ処理
//    → 1つ目のブロックの中身を関数にして、a と b を入れ替えて2回呼ぶ（2つ目のブロックは消える）
bool check(vector<int> a, vector<int> b) {
    // 18〜63行目をそのまま入れる
    return ans;
}
    // main の中（17〜125行目）
    if (check(a, b) || check(b, a)) cout << "Yes" << endl;
    else cout << "No" << endl;

// ② 46〜48行目：ans = false にした時点で答えは決まるので、すぐ抜ける
                if (a.at(i) != tmp) {
                    ans = false;
                    break;
                }

// ③ 33〜44行目：どの道でも最後は break するので 1つにまとめる
            if (i == n - 1) {
                if (!ok && a.at(n - 1) != tmp) ans = false;
                break;
            }
*/
