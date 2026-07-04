#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool flag_ten = false;
    bool flag_ami = false;
    int tmp = 0;
    int index = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (flag_ten && flag_ami && s.at(i) == '.') {
            s.at(tmp) = 'o';
            s.at(i) = 'o';
            flag_ami = false;
            index = i + 1;

        }
        else if (s.at(i) == '#' && flag_ten) {
            flag_ami = true;
        }
        else if (s.at(i) == '.' && !flag_ten && index < i) {
            flag_ten = true;
            tmp = i;
        }
    }
    if (count(s.begin(), s.end(), '#') == 0) {
        s.at(0) = 'o';
    }
    cout << s << endl;
}

// 【改善版】can_place 1つで済む。最初の '.' も自動で拾えるので count による特別処理も不要。
// bool can_place = true;
// for (int i = 0; i < (int)s.size(); i++) {
//     if (s.at(i) == '#') {
//         can_place = true;
//     } else if (can_place) {
//         s.at(i) = 'o';
//         can_place = false;
//     }
// }
// cout << s << endl;