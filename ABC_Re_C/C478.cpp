#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    vector<int> b(n + 1);
    vector<int> ans = a;
    sort(ans.begin(), ans.end());
    /*
    for (int i = 1; i <= n - k + 1; i++) {
        if (a.at(i) != ans.at(i) && ok) {
            for (int j = i; j <= i + k - 1; i++) {
                b.at(i) = a.at(i);
            }
            sort(b.begin() + i - 1, b.begin() + i + k);
            for (int j = i; j <= i + k - 1; i++) {
                if (b.at(i) != ans.at(i)) {
                    ok = false;
                }
            }
        }
    }
    */
    int low = n, high = 1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a.at(i) != ans.at(i)) {
            low = min(low, i);
            high = max(high, i);
            cnt++;
        }
    }
    cout << (high - low <= k - 1 && cnt > 0 || cnt == 0 ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. ずれが 1 つもないときは low = n, high = 1 のままで high − low はマイナスになり、<= k − 1 は必ず成り立つ。
      なので cnt がなくても同じ結果。条件は「ずれの幅が K 以内」だけで書ける（36・39 行目）
   2. 添字 0 の 0 も含めて sort している。値が 1 以上なのでたまたま先頭に残るが、1 番目から並べるほうが安全（15 行目）
   3. 13 行目の b と 16〜30 行目のコメントアウトは今の方針では使わないので消してよい。
      残すなら「こう考えたけど、こういう理由でやめた」を一言書いておくと復習で役立つ

   sort(ans.begin() + 1, ans.end());                    // 15 行目
   cout << (high - low + 1 <= k ? "Yes" : "No") << endl;  // 39 行目
*/
