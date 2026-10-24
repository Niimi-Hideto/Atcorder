#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int pre, cnt = 0;
    cin >> pre;

    bool ok = false;
    if (pre == k) {
        cnt++;
        ok = true;
    }

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;

        if (a == k && !ok) {
            cnt++;
            ok = true;
        }
        else if (a > k && pre < k && !ok) {
            cnt++;
        }
        else if (a < k && pre > k && !ok) {
            cnt++;
        }
        else {
            ok = false;
        }
        pre = a;
    }

    cout << cnt << endl;
}

/* ===== 改善点 =====
   1. ok はなくても答えが変わらない。ok が true になるのは点がちょうど K だった直後だけで、
      次の点は A_i ≠ A_{i+1} より K にならず、次の線分は始点が K なので K をまたぐこともない。
      「点がちょうど K」と「線分が K をまたぐ」は最初から重ならない（11・14・21–33 行目）

    (11・14 行目は消す)
        if (a == k) {                                  // 21–33 行目
            cnt++;
        }
        else if ((pre < k && k < a) || (a < k && k < pre)) {
            cnt++;
        }

   2. 最初のコードの原因は 2 つ。① ループの中で 1 つ前の点（y）しか K と比べておらず、最後の点 N を一度も調べていなかった
      ② ok が次の回まで残り、K の点のすぐ次の線分で K をまたいでも数えなかった（A = 1 3 5 1, K = 3 で 2 のはずが 1）。
      ②は 1 の ok を足したことで生まれたバグ。重なりそうだと思ったら、印を足す前に本当に重なる入力があるか例で確かめる
*/
