#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ab(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        ab.at(b).push_back(a);
        ab.at(a).push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        long long num = n - ab.at(i).size() - 1;
        if (num < 2) {
            cout << 0 << endl;
        }
        else {
            cout << num * (num - 1) * (num - 2) / 6 << endl;
        }
    }
}

// 改善案：
// ①隣接リスト(vector<vector<int>>)は不要。使ってるのは .size()（＝利害関係の人数）だけで、
//   「誰と関係があるか」は一度も参照してない。次数を数えるだけで足りる：
//     vector<int> deg(n + 1, 0);
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         cin >> a >> b;
//         deg.at(a)++;
//         deg.at(b)++;
//     }
//   → 前回の未復習メモ「具体的な候補者リストは不要、次数だけカウントすればいい」がこれ
//
// ②18行目：.size() は符号なし(size_t)なので式全体が符号なし計算になる。
//   結果が負になるケースでは破綻するので (long long) でキャストしておく方が安全
//
// ③19行目：3人選ぶので意図としては num < 3。
//   num == 2 でも公式が 2*1*0/6 = 0 を返すため結果は同じだが、条件が意図を表していない
