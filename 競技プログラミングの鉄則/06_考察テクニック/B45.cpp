#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = a + b + c;
    cout << (ans == 0 ? "Yes" : "No") << endl;
}

/* ===== 改善点 =====
   1. ans の中身は答えではなく「3 つの合計」なので sum にする

   long long sum = a + b + c;                     // 8 行目
   cout << (sum == 0 ? "Yes" : "No") << endl;     // 9 行目
*/

