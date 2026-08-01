#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, d;
    string s;
    cin >> m >> d >> s;

    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int cnt = 0;
        bool flag = true;
        if (s.at(i) == '.') {
            //左
            int k = i;
            while (cnt < d) {
                k--;
                if (k < 0) {
                    break;
                }
                if (s.at(k) == 'G') {
                    flag = false;
                }
                cnt++;
            }
            //右
            if (flag) {
                cnt = 0;
                k = i;
                while (cnt < d) {
                    k++;
                    if (k > (int)s.size() - 1) {
                        break;
                    }
                    if (s.at(k) == 'G') {
                        flag = false;
                    }
                    cnt++;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

/*
// 左右をまとめた版
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, d;
    string s;
    cin >> m >> d >> s;

    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s.at(i) == '.') {
            bool flag = true;
            for (int k = max(0, i - d); k <= min((int)s.size() - 1, i + d); k++) {
                if (s.at(k) == 'G') {
                    flag = false;
                }
            }
            if (flag) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
*/
