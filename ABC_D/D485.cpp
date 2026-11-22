#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int l = 1000000000, r = -1;
    bool a = false, b = false, c = false;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'A') {
            a = true;
        }
        else if (s.at(i) == 'B') {
            b = true;
        }
        else if (s.at(i) == 'C') {
            c = true;
        }

        if (a && b && c) {
            l = i;
            break;
        }
    }

    a = false, b = false, c = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s.at(i) == 'A') {
            a = true;
        }
        else if (s.at(i) == 'B') {
            b = true;
        }
        else if (s.at(i) == 'C') {
            c = true;
        }

        if (a && b && c) {
            r = i;
            break;
        }
    }

    long long ans = 0;
    a = false, b = false, c = false;
    int A = 0, B = 0, C = 0;
    for (int i = l + 1; i < r; i++) {
        if (!(a && b && c)) {
            if (s.at(i) == 'A') {
                a = true;
                A = i;
            }
            else if (s.at(i) == 'B') {
                b = true;
                B = i;
            }
            else if (s.at(i) == 'C') {
                c = true;
                C = i;
            }
        }
        else {
            if (s.at(i) == 'A') {
                A = i;
            }
            else if (s.at(i) == 'B') {
                B = i;
            }
            else if (s.at(i) == 'C') {
                C = i;
            }
        }

        if (a && b && c) {
            int mn = min({ A, B, C });
            ans += mn - (l + 1) + 1;
        }
    }

    cout << ans << endl;
}

/* 改善点（変わる行だけ）

// ① 50〜74行目：if / else のどちらでも位置の更新（A = i など）は同じ。フラグを true にし直しても何も変わらないので、
//    50行目の if と 64〜74行目の else を消して、51〜62行目だけを残す

// ② 文字を番号にする（s.at(i) - 'A' で A→0、B→1、C→2）。if の3段が1行になる
//    ・10行目と 12〜20行目・30〜38行目：フラグを vector に（28行目は seen = vector<bool>(3); で戻す）
    vector<bool> seen(3);
        seen.at(s.at(i) - 'A') = true;
        if (seen.at(0) && seen.at(1) && seen.at(2)) {
//    ・47・48行目と 50〜74行目：位置を -1 で始めれば、3つとも見つかったかが位置だけで分かるのでフラグもいらない
//      （76行目の if は mn != -1 に変わる）
    vector<int> last(3, -1);
        last.at(s.at(i) - 'A') = i;
        int mn = min({ last.at(0), last.at(1), last.at(2) });
        if (mn != -1) ans += mn - l;

// ③ 78行目：始まりに選べるのは l + 1 〜 mn なので、個数は mn - l
            ans += mn - l;
*/
