#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, s;
    cin >> t >> s;

    int count = 0;
    for (int i = 0; i < (int)t.size() - (int)s.size() + 1; i++) {
        count = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (t.at(j + i) == s.at(j) || t.at(j + i) == '?') {
                count++;
            }
        }
        if (count == (int)s.size()) {
            break;
        }
    }

    if (count == (int)s.size()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

// 【改善版】count は std::count と名前が被る。bool flag で意図を明確に
// bool found = false;
// for (int i = 0; i <= (int)t.size() - (int)s.size(); i++) {
//     bool ok = true;
//     for (int j = 0; j < (int)s.size(); j++) {
//         if (t.at(i + j) != s.at(j) && t.at(i + j) != '?') { ok = false; break; }
//     }
//     if (ok) { found = true; break; }
// }
// cout << (found ? "Yes" : "No") << endl;
