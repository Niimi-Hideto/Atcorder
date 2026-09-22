#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    vector<int> l(d + 1), r(d + 1);
    for (int i = 0; i < n; i++) {
        int tmp_l, tmp_r;
        cin >> tmp_l >> tmp_r;

        l.at(tmp_l)++;
        r.at(tmp_r)++;
    }

    vector<int> l_sum(d + 1), r_sum(d + 1);
    for (int i = 1; i <= d; i++) {
        l_sum.at(i) = l_sum.at(i - 1) + l.at(i);
        r_sum.at(i) = r_sum.at(i - 1) + r.at(i);

    }

    for (int i = 1; i <= d; i++) {
        cout << l_sum.at(i) - r_sum.at(i - 1) << endl;
    }
}

/* ===== 改善点（いもす法）=====
   l_sum[d] - r_sum[d-1] は「L に +1、R+1 に -1 を書き込んだ配列の累積和」と同じ。
   差を最後に取る代わりに、最初に1本の配列へ書き込んでおけば配列が4本→2本になる

   vector<int> b(d + 2);           // R+1 = D+1 まで書き込むので d+2
   b.at(tmp_l) += 1;               // 来始める日に +1
   b.at(tmp_r + 1) -= 1;           // 帰った翌日に -1

   vector<int> ans(d + 1);
   ans.at(i) = ans.at(i - 1) + b.at(i);
   cout << ans.at(i) << endl;
*/
