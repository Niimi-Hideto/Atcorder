#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string s, t;

    cin >> n >> m >> s >> t;

    int count = 1000;
    int tmp = 0;

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = i; j < m + i; j++) {
            if (s.at(j) == t.at(j - i)) {
                continue;
            }
            else if (s.at(j) > t.at(j - i)) {
                tmp += (s.at(j) - t.at(j - i));
            }
            else {
                tmp += (10 - t.at(j - i) + s.at(j));
            }
        }
        count = min(tmp, count);
        tmp = 0;
    }
    cout << count << endl;
}
