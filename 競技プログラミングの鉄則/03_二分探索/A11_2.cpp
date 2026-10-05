#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int left = 0, right = n - 1, mid = 0;
    while (left <= right) {
        mid = (right + left) / 2;
        if (a.at(mid) == x) {
            break;
        }
        else if (a.at(mid) < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << mid + 1 << endl;
}

/* ===== 改善点 =====
   1. 見つけたその場で出力して return する。mid をループの外で宣言しなくてよくなり、
      X が見つからない問題に使い回しても古い mid を出す心配がない（26 行目の出力は不要になる）

   int left = 0, right = n - 1;
   int mid = (right + left) / 2;
   if (a.at(mid) == x) {
       cout << mid + 1 << endl;
       return 0;
   }
*/
