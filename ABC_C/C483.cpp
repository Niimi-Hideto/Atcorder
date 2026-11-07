#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vote(n + 1);
    vector<vector<int>> move(n + 1);
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a.at(i) >> b.at(i);

        move.at(a.at(i)).push_back(b.at(i));
        vote.at(a.at(i))++;
    }

    vector<int> victory(n + 1);
    vector<pair<int, int>> tmp(n + 1);
    for (int i = 1; i <= n; i++) {
        tmp.at(i) = { vote.at(i), -i };
    }
    sort(tmp.begin(), tmp.end());

    for (int i = 1; i <= n; i++) {
        if (tmp.at(n).second != i * -1) {
            victory.at(i) = tmp.at(n).second * -1;
        }
        else {
            victory.at(i) = tmp.at(n - 1).second * -1;
        }
    }

    for (int k = 1; k <= n; k++) {
        int vic = victory.at(k);
        for (int x : move.at(k)) {
            vote.at(x)++;

            if (vote.at(vic) == vote.at(x)) {
                vic = min(vic, x);
            }
            else if (vote.at(vic) < vote.at(x)) {
                vic = x;
            }
        }
        cout << vic << endl;

        for (int x : move.at(k)) {
            vote.at(x)--;
        }
    }
}

/* ===== 改善点 =====
   1. tmp.at(0) の {0, 0} もソートに入っている。番号を -i にしたので {0, 0} は「票0の候補者」より後ろに並び、
      2位の票が0だと tmp.at(n - 1) が {0, 0} になって victory に 0 が入る（k の票が必ず誰かに移って上書きされるので偶然通っている）。
      1番からだけ並べれば偶然に頼らない

   sort(tmp.begin() + 1, tmp.end());

   2. a, b は読み込んだその場でしか使わないので配列にしなくていい（10行目を消して、11〜16行目のループの中を次に）

       int a, b;
       cin >> a >> b;
       move.at(a).push_back(b);
       vote.at(a)++;

   3. victory は k ごとに1回使うだけなので、配列にせず35行目でその場で決めればいい（18行目と25〜32行目が要らない）

       int vic = (tmp.at(n).second * -1 != k) ? tmp.at(n).second * -1 : tmp.at(n - 1).second * -1;

   4. （公式解説の形）「k が1位なら2位を使う」の if をなくす。k の票を0にして、「票が増えた人＋1位＋2位」をまとめて比べる。
      辞退するのは1人だけなので、1位と2位を両方候補に入れれば片方は必ず残る。k は票が0なので勝手に負ける。
      今回のWAは2回ともこの if の部分（29行目の vic の初期値、26行目の -i との比較）だった。
      比べるときも (票数, -番号) の pair の max を取れば「票数最大、同じなら番号最小」になる（3は使わず、18行目・25〜51行目を次に置き換える）

   int c1 = -tmp.at(n).second;      // 辞退なしでの1位
   int c2 = -tmp.at(n - 1).second;  // 辞退なしでの2位
   for (int k = 1; k <= n; k++) {
       for (int x : move.at(k)) {
           vote.at(x)++;
       }
       int save = vote.at(k);
       vote.at(k) = 0;

       pair<int, int> best = {-1, 0};  // (票数, -番号)
       for (int x : move.at(k)) {
           best = max(best, {vote.at(x), -x});
       }
       best = max(best, {vote.at(c1), -c1});
       best = max(best, {vote.at(c2), -c2});
       cout << -best.second << endl;

       vote.at(k) = save;
       for (int x : move.at(k)) {
           vote.at(x)--;
       }
   }
*/
