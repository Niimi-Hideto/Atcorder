#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x;

    cin >> n >> x;

    vector <int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    for (int i = 0; i < n; i++) {
        if (vec.at(i) < x) {
            x = vec.at(i);
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}

/*
// push_back版
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);  // 読んだ値を追加
    }

    for (int i = 0; i < n; i++) {
        if (vec.at(i) < x) {
            x = vec.at(i);
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
*/
