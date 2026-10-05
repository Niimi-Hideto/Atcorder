#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long a, b, c, ab, bc, ca, abc;
    a = n / 3;
    b = n / 5;
    c = n / 7;
    ab = n / 15;
    bc = n / 35;
    ca = n / 21;
    abc = n / 105;

    cout << a + b + c - ab - bc - ca + abc << endl;
}
