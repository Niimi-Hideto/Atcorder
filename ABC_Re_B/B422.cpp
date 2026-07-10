#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h + 2, vector<char>(w + 2, '.'));
    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            cin >> s.at(i).at(j);
        }
    }

    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            if (s.at(i).at(j) == '#') {
                int num = 0;
                if (s.at(i).at(j - 1) == '#') {
                    num++;
                }
                if (s.at(i - 1).at(j) == '#') {
                    num++;
                }
                if (s.at(i).at(j + 1) == '#') {
                    num++;
                }
                if (s.at(i + 1).at(j) == '#') {
                    num++;
                }

                if (num % 2 != 0 || num == 0) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}
