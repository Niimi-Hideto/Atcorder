#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int num1 = 0, num2 = 0, num3 = 0;

    num1 = count(s.begin(), s.end(), '1');
    num2 = count(s.begin(), s.end(), '2');
    num3 = count(s.begin(), s.end(), '3');

    if (num1 == 1 && num2 == 2 && num3 == 3) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}