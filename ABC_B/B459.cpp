#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if ('a' <= (s.at(0)) && (s.at(0)) <= 'c') {
            cout << 2;
        }
        else if ('d' <= (s.at(0)) && (s.at(0)) <= 'f') {
            cout << 3;
        }
        else if ('g' <= (s.at(0)) && (s.at(0)) <= 'i') {
            cout << 4;
        }
        else if ('j' <= (s.at(0)) && (s.at(0)) <= 'l') {
            cout << 5;
        }
        else if ('m' <= (s.at(0)) && (s.at(0)) <= 'o') {
            cout << 6;
        }
        else if ('p' <= (s.at(0)) && (s.at(0)) <= 's') {
            cout << 7;
        }
        else if ('t' <= (s.at(0)) && (s.at(0)) <= 'v') {
            cout << 8;
        }
        else if ('w' <= (s.at(0)) && (s.at(0)) <= 'z') {
            cout << 9;
        }
    }
    cout << endl;
}

// vector版
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//
//     vector<string> groups = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//
//     for (int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         char c = s.at(0);
//         for (int j = 0; j < (int)groups.size(); j++) {
//             if (count(groups.at(j).begin(), groups.at(j).end(), c) > 0) {
//                 cout << j + 2;
//                 break;
//             }
//         }
//     }
//     cout << endl;
// }