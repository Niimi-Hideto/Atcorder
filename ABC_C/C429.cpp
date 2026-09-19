#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());

    long long old, now, cnt = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            old = a.at(i);
            continue;
        }

        now = a.at(i);
        if (now == old) {
            cnt++;
        }
        else {
            ans += (cnt * (cnt - 1) / 2) * (n - cnt);
            cnt = 1;
        }
        old = now;
    }
    if (cnt != 1 && n != cnt) {
        ans += (cnt * (cnt - 1) / 2) * (n - cnt);
    }

    cout << ans << endl;
}

/* ===== 改善版（今の知識範囲での書き方）=====

   一番大きい変更：ソートが要らない
   制約が 1 ≤ A_i ≤ N なので、値をそのまま添字にして数えられる。
   欲しかったのは「各値が何個あるか」だけで、順序は一度も使っていなかった。
   ソートは「順序が要るとき」だけ使う道具。
   （ABC439 C・ABC474 Cとまったく同じ「値の範囲が1〜N → 添字で数える」パターン）

   これで消えるもの
   - sort               … O(N log N) → O(N)
   - old / now          … 「直前の値と同じか」を見る必要がない
   - if (i == 1) の特別扱い … ループ前からcntが全部揃っている
   - ループ後の最後のflush  … 同上
   - vector<int> a      … 配列を保持せず読み捨てでよい

   ほかの直した点
   - vector<int> a(n+1) を丸ごとsortしていたのは運頼み（a[0]=0がA_i≥1のおかげで
     先頭に来てループから外れていただけ。0や負の値があり得たら壊れる）
   - if (cnt != 1 && n != cnt) は不要。cnt==1ならC(1,2)=0、cnt==nならn-cnt=0で
     どちらも足して0。条件を書くほうが読む側に負担がかかるし、間違えると本物の
     グループを落とす
   - old / now は long long でなくてよい（溢れるのは cnt と ans だけ）

int main() {
    int n;
    cin >> n;

    // cnt.at(v) = 値vが何個あるか。値の範囲が1〜Nなので添字にできる
    vector<long long> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt.at(x)++;
    }

    // 「ちょうど2種類」= 同じ値を2個 + 違う値を1個
    //   同じ値2個の選び方 … C(cnt, 2)
    //   残り1個の選び方   … n - cnt（その値以外すべて）
    // cntがlong longなので cnt*(cnt-1) の途中でも溢れない
    long long ans = 0;
    for (int v = 1; v <= n; v++) {
        ans += cnt.at(v) * (cnt.at(v) - 1) / 2 * (n - cnt.at(v));
    }

    cout << ans << endl;
}

===== ここまで ===== */
