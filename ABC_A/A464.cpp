#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int e, w;

    e = count(s.begin(), s.end(), 'E');
    w = count(s.begin(), s.end(), 'W');

    if (e > w) {
        cout << "East" << endl;
    }
    else {
        cout << "West" << endl;
    }


}
