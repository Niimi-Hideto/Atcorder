#include <bits/stdc++.h>
using namespace std;

int main() {
    string d;
    cin >> d;

    if (d == "N") {
        cout << 'S' << endl;
    }
    else if (d == "E") {
        cout << 'W' << endl;
    }
    else if (d == "W") {
        cout << 'E' << endl;
    }
    else if (d == "S") {
        cout << 'N' << endl;
    }
    else if (d == "NE") {
        cout << "SW" << endl;
    }
    else if (d == "NW") {
        cout << "SE" << endl;
    }
    else if (d == "SE") {
        cout << "NW" << endl;
    }
    else if (d == "SW") {
        cout << "NE" << endl;
    }
}
