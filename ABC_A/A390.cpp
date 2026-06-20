#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(5);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) >> vec.at(3) >> vec.at(4);

    int sp = 0;

    for (int i = 0; i < 4; i++) {
        if (vec.at(i + 1) - vec.at(i) == -1) {
            sp++;
            swap(vec.at(i), vec.at(i + 1));
        }
    }

    if (is_sorted(vec.begin(), vec.end()) && sp == 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
