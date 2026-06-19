#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double num = a / b;
    int i = 0;


    while (true) {
        if (i < num) {
            i++;
        }
        else {
            break;
        }
    }
    if (num - (i - 1) > i - num) {
        cout << i << endl;
    }
    else {
        cout << i - 1 << endl;
    }
}

// 整数で受け取って除算時にキャストする書き方
// int a, b;
// cin >> a >> b;
// double num = (double)a / b;
