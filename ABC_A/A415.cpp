#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    bool flag = false;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    cin >> x;

    for (int i = 0; i < n; i++) {
        if (vec.at(i) == x) {
            cout << "Yes" << endl;
            flag = true;
            break;
        }
    }

    if (flag == false) {
        cout << "No" << endl;
    }
}

// 別解：count(begin, end, 値) でvector内の個数を数える
// if (count(vec.begin(), vec.end(), x) > 0) cout << "Yes";
// else cout << "No";
