#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    deque<int> d;
    bool flip = false;

    for (int i = 0; i < n; i++) {
        if (flip) {
            d.push_front(i + 1);
        }
        else {
            d.push_back(i + 1);
        }
        if (s.at(i) == 'o') {
            flip = !flip;
        }
    }
    if (flip) {
        reverse(d.begin(), d.end());
    }
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;
}
