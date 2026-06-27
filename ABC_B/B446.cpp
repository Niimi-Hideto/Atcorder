#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(m, 1);

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        bool flag = true;
        for (int j = 0; j < l; j++) {
            int tmp;
            cin >> tmp;

            if ((1 == vec.at(tmp - 1)) && flag) {
                cout << tmp << endl;
                vec.at(tmp - 1) = 0;
                flag = false;
            }
            else if ((j == l - 1) && flag) {
                cout << 0 << endl;
            }
        }
    }
}

// 内側ループ後・外側ループ内に if (flag) cout << 0 << endl; と書く方が「全部回しても選べなかったら水」と意図が読みやすい
