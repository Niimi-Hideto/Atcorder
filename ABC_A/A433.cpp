#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    bool flag = false;

    cin >> x >> y >> z;

    while (x < 100) {
        if (y * z == x) {
            cout << "Yes" << endl;
            flag = true;
            break;
        }
        x++;
        y++;
    }

    if (flag != true) {
        cout << "No" << endl;
    }
}

/*
// 別解：数学的アプローチ（年齢差は常に一定）
// x = z*y のとき x-y = (z-1)*y → y = (x-y)/(z-1) が正整数かどうかだけ判定
// if (x > y && (x - y) % (z - 1) == 0) cout << "Yes";
// else cout << "No";
*/
