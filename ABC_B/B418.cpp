#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int size = (int)s.size();
    double ans = 0;
    for (int i = 0; i < size - 2; i++) {
        if (s.at(i) == 't') {
            for (int j = i + 1; j < size; j++) {
                double num = 0;
                if (s.at(j) == 't' && j - i >= 2) {
                    string tmp = s.substr(i, j - i + 1);
                    double t = 0;
                    for (int k = 0; k < tmp.size(); k++) {
                        if (tmp.at(k) == 't') {
                            t++;
                        }
                    }
                    num = (t - 2) / ((double)tmp.size() - 2);
                    ans = max(ans, num);
                }
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}

// 【改善版】count() で t のカウントを1行に、num を削除してすっきり
// for (int i = 0; i < size - 2; i++) {
//     if (s.at(i) == 't') {
//         for (int j = i + 2; j < size; j++) {
//             if (s.at(j) == 't') {
//                 string tmp = s.substr(i, j - i + 1);
//                 double t = count(tmp.begin(), tmp.end(), 't');
//                 ans = max(ans, (t - 2) / ((double)tmp.size() - 2));
//             }
//         }
//     }
// }
