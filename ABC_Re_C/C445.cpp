#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<int> last(n + 1);

    for (int i = n; i >= 1; i--) {
        if (a.at(i) == i) {
            last.at(i) = a.at(i);
        }
        else {
            last.at(i) = last.at(a.at(i));
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << last.at(i) << " ";
    }
    cout << endl;
}

// 改善案：
// ①17行目は a.at(i) == i が成立してる分岐なので、last.at(i) = i; と書いた方が
//   「ここが不動点で自分自身に留まる」という意味が直接伝わる
// ②変数名 last は、ABC474 Cで「最後に操作された"時刻"」の意味で使ったばかり。
//   ここは「最終的な"行き先"」なので、dest や final_pos の方が意味が明確
