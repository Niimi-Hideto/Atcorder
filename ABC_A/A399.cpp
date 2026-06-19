#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s.at(i) != t.at(i)) {
            count++;
        }
    }
    cout << count << endl;
}

