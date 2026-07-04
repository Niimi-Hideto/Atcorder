#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    int b = 0;
    for (int i = 0; i < m; i++) {
        cin >> b;
        if (count(a.begin(), a.end(), b) != 0) {
            for (int j = 0; j < n; j++) {
                if (a.at(j) == b) {
                    a.erase(a.begin() + j);
                    break;
                }
            }
        }
    }
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

// 【改善版】count チェック不要・n → a.size() で安全に
// for (int i = 0; i < m; i++) {
//     cin >> b;
//     for (int j = 0; j < (int)a.size(); j++) {
//         if (a.at(j) == b) {
//             a.erase(a.begin() + j);
//             break;
//         }
//     }
// }