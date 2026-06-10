#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    string result;


    for (int i = 0; i < s.size(); i++) {
        if (i + 1 <= n) {
            continue;
        }
        else if (i + 1 >= s.size() - (n - 1)) {
            continue;
        }
        else {
            result += s.at(i);
        }

    }
    cout << result << endl;
}

// 改善版（||でまとめる）
// for (int i = 0; i < s.size(); i++) {
//     if (i + 1 <= n || i + 1 >= s.size() - (n - 1)) continue;
//     result += s.at(i);
// }

