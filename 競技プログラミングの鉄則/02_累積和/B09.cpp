#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int size = 1500;

    vector<vector<int>> square(size + 1, vector<int>(size + 1));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        square.at(a).at(b)++;
        square.at(c).at(d)++;
        square.at(c).at(b)--;
        square.at(a).at(d)--;
    }

    //横累積
    for (int i = 0; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            square.at(i).at(j) += square.at(i).at(j - 1);
        }
    }

    //縦累積
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            square.at(i).at(j) += square.at(i - 1).at(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (square.at(i).at(j) > 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
