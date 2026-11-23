#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> voted(n + 1);
    vector<vector<int>> vote(n + 1);
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a.at(i) >> b.at(i);

        voted.at(a.at(i))++;
        vote.at(a.at(i)).push_back(b.at(i));
    }

    vector<pair<int, int>> tmp(n + 1);
    for (int i = 1; i <= n; i++) {
        tmp.at(i).first = voted.at(i);
        tmp.at(i).second = i * -1;
    }
    sort(tmp.begin() + 1, tmp.end());
    vector<int> ans;
    ans.push_back(tmp.at(n).second * -1);
    ans.push_back(tmp.at(n - 1).second * -1);

    for (int i = 1; i <= n; i++) {
        vector<int> ans_2 = ans;
        ans_2.push_back(i);
        pair<int, int> ans_3 = { 0, n + 1 };
        for (int x : vote.at(i)) {
            voted.at(x)++;
            voted.at(i)--;
            ans_2.push_back(x);
        }

        for (int x : ans_2) {
            if (ans_3.first < voted.at(x)) {
                ans_3.first = voted.at(x);
                ans_3.second = x;
            }
            else if (ans_3.first == voted.at(x)) {
                ans_3.second = min(ans_3.second, x);
            }
        }
        cout << ans_3.second << endl;

        for (int x : vote.at(i)) {
            voted.at(x)--;
            voted.at(i)++;
        }
    }
}

/* 改善点（変わる行だけ）

// ① 30行目：辞退した候補者 i は当選の候補に入れなくていい（34行目で i の票が0になるので、たまたま当選しないだけ）。この行を消す

// ② 変数名を中身に合わせる（どれも出力する答えそのものではない）
//    ans → top（辞退なしの上位2人）、ans_2 → cand（当選の候補）、ans_3 → best（今のところ一番の人）
    vector<int> top;
        vector<int> cand = top;
        pair<int, int> best = { 0, n + 1 };

// ③ 21・25・26行目：i * -1 は -i と書ける
        tmp.at(i).second = -i;
    top.push_back(-tmp.at(n).second);
    top.push_back(-tmp.at(n - 1).second);
*/
