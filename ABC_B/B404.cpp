#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<string>& s, int n) {
    vector<string> tmp(n, string(n, '.'));  // n×n の空グリッドを用意
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp.at(j).at(n - 1 - i) = s.at(i).at(j);  // (i,j) → (j, n-1-i)
        }
    }
    s = tmp;  // 参照渡しなので、これで呼び出し元の s が書き変わる
}

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    vector<string> t(n);
    for (int i = 0; i < n; i++) cin >> s.at(i);
    for (int i = 0; i < n; i++) cin >> t.at(i);

    int ans = INT_MAX;
    for (int rot = 0; rot < 4; rot++) {   // 0〜3回回転を全試し
        int diff = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s.at(i).at(j) != t.at(i).at(j)) diff++;
        ans = min(ans, rot + diff);        // 回転回数 + 色変更回数
        rotate90(s, n);                    // 次の回転へ
    }

    cout << ans << endl;
}
