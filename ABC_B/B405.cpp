#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    bool flag = true;
    int ans = 0;
    while (flag) {
        for (int i = 1; i <= m; i++) {
            if (count(a.begin(), a.end(), i) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            a.erase(a.begin() + (int)a.size() - 1);
            ans++;
        }
    }
    cout << ans << endl;
}

// 【改善版】末尾削除は pop_back() で書ける
// a.pop_back();
