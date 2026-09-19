#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    // '(' を +1、')' を -1 として、先頭から足した値を「収支」と呼ぶ。
    //   bal.at(len) = 先頭len文字ぶんの収支
    //   mn.at(len)  = 先頭0文字〜len文字までの収支の最小値
    // 添字0は「空文字列」を表す番兵（空文字列は良い括弧列なので収支0・最小値0）
    vector<int> bal, mn;
    bal.push_back(0);
    mn.push_back(0);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            char c;
            cin >> c;

            // 末尾に1文字足すと、収支は直前の値から±1するだけ
            int b = bal.back() + (c == '(' ? 1 : -1);
            bal.push_back(b);
            // 最小値も「直前までの最小値」と「今の収支」を比べるだけで済む
            mn.push_back(min(mn.back(), b));
        }
        else {
            // 末尾を消すだけ。前の状態がそのまま下に残っているので復元作業がいらない
            bal.pop_back();
            mn.pop_back();
        }

        // 良い括弧列 ⇔ 全体の収支が0 かつ 途中で一度もマイナスにならない
        cout << (bal.back() == 0 && mn.back() >= 0 ? "Yes" : "No") << "\n";
    }
}
