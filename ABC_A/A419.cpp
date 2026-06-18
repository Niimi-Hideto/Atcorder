#include <bits/stdc++.h>
using namespace std;

int main() {
    string r, b, g;
    r = "red";
    b = "blue";
    g = "green";
    string s;

    cin >> s;

    if (s == r) {
        cout << "SSS" << endl;
    }
    else if (s == b) {
        cout << "FFF" << endl;
    }
    else if (s == g) {
        cout << "MMM" << endl;
    }
    else {
        cout << "Unknown" << endl;
    }
}

// 別解：中間変数不要、直接文字列リテラルと比較
// if (s == "red") cout << "SSS";
// else if (s == "blue") cout << "FFF";
// else if (s == "green") cout << "MMM";
// else cout << "Unknown";
