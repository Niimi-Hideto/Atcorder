#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) >> vec.at(3);

    sort(vec.begin(), vec.end());

    if (((vec.at(0) == vec.at(1)) && (vec.at(1) != vec.at(2)) && (vec.at(2) == vec.at(3)))
        || ((vec.at(0) == vec.at(1)) && (vec.at(1) == vec.at(2)) && (vec.at(2) != vec.at(3)))
        || (vec.at(0) != vec.at(1)) && (vec.at(1) == vec.at(2) && (vec.at(2) == vec.at(3)))) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
