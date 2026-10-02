#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a1 = 1, a2 = 1, an = 0;
    for (int i = 3; i <= n; i++) {
        an = a1 + a2;

        an %= 1000000007;
        a2 = a1;
        a1 = an;
    }
    cout << an << endl;
}

/* ===== 改善点 =====
   a1・a2 だと問題文の第1項・第2項に見えるが、中身は「1つ前の項」と「2つ前の項」。
   名前を中身に合わせると、更新の順番（2つ前 ← 1つ前 ← 今）が読み取りやすい

   int prev1 = 1, prev2 = 1, cur = 0;   // 1つ前、2つ前、今の項
   cur = prev1 + prev2;
   cur %= 1000000007;
   prev2 = prev1;
   prev1 = cur;
*/
