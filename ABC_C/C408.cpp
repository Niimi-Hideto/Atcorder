#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> block(n + 2);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        block.at(l)++;
        block.at(r + 1)--;
    }

    vector<int> block_pre(n + 2);
    for (int i = 1; i <= n; i++) {
        block_pre.at(i) = block_pre.at(i - 1) + block.at(i);
    }

    const int INF = 1000000000;
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, block_pre.at(i));
    }

    cout << ans << endl;
}

/* 改善点（変わる行だけ）

// 名前：block は差分なので diff、block_pre は「城壁 i を守っている砲台の数」なので cnt
    vector<int> diff(n + 2);
    vector<int> cnt(n + 2);

// 17〜26行目：累積を作りながら最小も取れば、ループは 1 つで済む（INF・ans は先に宣言しておく）
    for (int i = 1; i <= n; i++) {
        cnt.at(i) = cnt.at(i - 1) + diff.at(i);
        ans = min(ans, cnt.at(i));
    }
*/
