#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 残っている列を「(値, その値が連続している個数)」の塊のリストとして持つ
    // 末尾（back）が現在の列の一番後ろ。配列を作り直す必要がなくなる
    // 隣り合う塊は必ず違う値になる（同じ値なら1つの塊にまとめるため）
    vector<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (!st.empty() && st.back().first == a) {
            // 末尾の塊と同じ値 → その塊の連続数を増やすだけ
            st.back().second++;
        }
        else {
            // 違う値 → 新しい塊として末尾に積む
            st.push_back({ a, 1 });
        }

        if (st.back().second == 4) {
            // 4つ揃ったので、その塊ごと削除する
            st.pop_back();
            // 削除によって「その手前の塊」と「次に来る要素」が隣り合うことになるが、
            // 次のループでその塊（新しいback）と比較されるので、自動的に繋がる
        }
    }

    // 残った塊の個数を全部足したものが最終的な長さ
    int ans = 0;
    for (int i = 0; i < (int)st.size(); i++) {
        ans += st.at(i).second;
    }
    cout << ans << endl;
}
