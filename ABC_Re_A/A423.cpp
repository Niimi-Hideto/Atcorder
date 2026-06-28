#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, c;
    cin >> x >> c;           // 残高 x、手数料 c を読む

    int k = x / (1000 + c); // 1回の引き出しで 1000+c 減る。
    // 何回引き出せるか = x を (1000+c) で割った商（切り捨て）

    cout << k * 1000 << endl; // k回引き出せるので、実際に手元に入るのは k*1000 円
}

//また解けませんでした．
