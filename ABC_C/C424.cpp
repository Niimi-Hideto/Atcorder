#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> learned(n + 1);
    vector<vector<int>> skills(n + 1);

    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            learned.at(i) = true;
            q.push(i);
            ans++;
        }
        else {
            skills.at(a).push_back(i);
            skills.at(b).push_back(i);
        }
    }

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (int x : skills.at(tmp)) {
            if (learned.at(x) == false) {
                q.push(x);
                learned.at(x) = true;
                ans++;
            }
        }
    }

    cout << ans << endl;
}

/* ===== 改善点 =====
   1. skills の中身は「スキル v を習得すると、次に習得できるようになるスキルの一覧」なので unlock などの名前にする
      （next は std::next と名前がかぶるので避ける）
   2. tmp は「今処理しているスキル」なので cur などにする

   vector<vector<int>> unlock(n + 1);   // 9 行目（22・23・31 行目も同じ名前にそろえる）
   int cur = q.front();                 // 28 行目
   for (int x : unlock.at(cur)) {       // 31 行目
*/
