#include <bits/stdc++.h>
using namespace std;

long long check(int n, vector<int> a) {
    long long sum = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        sum += (n / a.at(i));
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int left = 0, right = 1000000000;
    while (left < right) {
        int mid = (left + right) / 2;
        long long tmp = check(mid, a);
        if (tmp >= k) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << right << endl;
}

/* ===== 改善点 =====
   1. check の引数 n は「台数」ではなく「秒数」なので t などにする（main の n と混ざる）
   2. check は true / false ではなく枚数を返すので count_printed などにし、tmp も printed にする

   long long count_printed(int t, vector<int> a) {   // 4 行目
       sum += t / a.at(i);                           // 7 行目
   long long printed = count_printed(mid, a);       // 24 行目
   if (printed >= k) {                               // 25 行目
*/
