#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long m) {
    long long p = a, answer = 1;
    for (int i = 0; i < 30; i++) {
        if ((b >> i) & 1) {
            answer = (answer * p) % m;
        }
        p = (p * p) % m;
    }
    return answer;
}

long long dev(long long a, long long b, long long m) {
    return (a * power(b, m - 2, m) % m);
}

int main() {
    int h, w;
    cin >> h >> w;

    long long m = 1000000007, tmp = h + w - 2;
    long long a = 1;
    for (int i = 1; i <= tmp; i++) {
        a = (a * i) % m;
    }
    long long b = 1;
    for (int i = 1; i <= h - 1; i++) {
        b = (b * i) % m;
    }
    for (int i = 1; i <= w - 1; i++) {
        b = (b * i) % m;
    }
    /*
    long long c = 1;
    for (int i = 1; i <= w - 1; i++) {
        c = (c * i) % m;
    }
    for (int i = 1; i <= h - 1; i++) {
        c = (c * i) % m;
    }
    */

    cout << (dev(a, b, m)) % m << endl;
}

/* ===== 改善点 =====
   1. dev は division（割り算）とつづりまで書くと読み間違えない（div は標準の関数と名前がぶつかるので避ける）
   2. division の中で % m まで済んでいるので、出力でもう一度 % m しなくてよい
   3. コメントアウトした c（35〜43行目）は使わないので消してよい

   long long division(long long a, long long b, long long m) {
   cout << division(a, b, m) << endl;
*/
