#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result;

    s.at(0) = tolower(s.at(0));

    result = "Of" + s;

    cout << result << endl;
}
