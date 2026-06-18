#include <bits/stdc++.h>
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;

    if (y == "Ocelot") {
        cout << "Yes" << endl;
    }
    else if ((y == "Serval" && x == "Serval") || (y == "Serval" && x == "Lynx")) {
        cout << "Yes" << endl;
    }
    else if (y == "Lynx" && x == "Lynx") {
        cout << "Yes" << endl;
    }

    else {
        cout << "No" << endl;
    }
}

// 別解：y == "Serval" の条件をまとめられる
// else if (y == "Serval" && (x == "Serval" || x == "Lynx"))
