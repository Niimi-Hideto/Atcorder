#include <bits/stdc++.h>
using namespace std;

int main() {
    double x;
    cin >> x;

    if (x < 37.5) {
        cout << 3 << endl;
    }
    else if (x >= 37.5 && x < 38.0) {
        cout << 2 << endl;
    }
    else {
        cout << 1 << endl;
    }
}

// else if の条件は x < 38.0 だけでよい（else if に入る時点で x >= 37.5 は確定）
// else if (x < 38.0) {
