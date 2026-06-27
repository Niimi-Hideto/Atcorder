#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 0;

    vector<string> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
        m = max(m, (int)(vec.at(i)).size());
    }

    for (int i = 0; i < n; i++) {
        if ((int)(vec.at(i)).size() == m) {
            cout << vec.at(i) << endl;
        }
        else {
            int count = 0;
            count = (m - (int)(vec.at(i)).size()) / 2;
            cout << string(count, '.') << vec.at(i) << string(count, '.') << endl;
        }
    }
}

// size()==m のとき count=0 になり string(0,'.')は空文字列なので if/else 不要。else だけで統一できる
// 変数名 count は std::count と被るので k などにしておくと安全
