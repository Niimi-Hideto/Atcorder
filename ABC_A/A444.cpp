#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    if (n.at(0) == n.at(1) && n.at(0) == n.at(2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

/*
// 別解：整数で桁を取り出す
// int n; cin >> n;
// int h = n / 100;        // 百の位
// int t = (n / 10) % 10;  // 十の位（/で1桁落とし、%で下だけ残す）
// int o = n % 10;         // 一の位
// if (h == t && h == o) { ... }
*/
