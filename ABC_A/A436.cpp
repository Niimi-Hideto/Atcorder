#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    string result = s;


    while ((int)result.size() < n) {
        result = 'o' + result;
    }
    cout << result << endl;
}

// 別解：string(個数, 文字) で指定文字を並べた文字列を作れる
// cout << string(n - s.size(), 'o') + s << endl;
