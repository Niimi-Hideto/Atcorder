#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    int tmp = 0;
    vector<int> ans;
    for (int i = 0; i < (int)a.size(); i++) {
        tmp = a.at(i);
        if (count(ans.begin(), ans.end(), tmp) == 0) {
            ans.push_back(tmp);
        }
    }

    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
}

// 【改善版】ソート済みなので ans.back() と比較するだけでいい。count 不要で O(1)
// for (int i = 0; i < (int)a.size(); i++) {
//     if (ans.empty() || a.at(i) != ans.back()) {
//         ans.push_back(a.at(i));
//     }
// }