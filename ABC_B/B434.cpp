#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i).at(0) >> vec.at(i).at(1);
    }

    double ave;
    double count;

    for (int i = 0; i < m; i++) {
        ave = 0;
        count = 0;
        for (int j = 0; j < n; j++) {
            if (vec.at(j).at(0) == i + 1) {
                ave += vec.at(j).at(1);
                count++;
            }
        }
        cout << fixed << setprecision(5) << ave / count << endl;
    }
}
