#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> taka(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> taka.at(i).at(j);
            if (j == 1) {
                taka.at(i).at(1) *= 60;
            }
        }
    }

    int q;
    cin >> q;
    int tmp = 0;

    for (int k = 0; k < q; k++) {
        cin >> tmp;
        tmp = (tmp * 60) + 30;

        vector<int> vec(n);

        for (int i = 0; i < n; i++) {
            if (taka.at(i).at(1) > tmp) {
                vec.at(i) = taka.at(i).at(0);
            }
        }
        int idx;
        idx = max_element(vec.begin(), vec.end()) - vec.begin();
        cout << vec.at(max_element(vec.begin(), vec.end()) - vec.begin()) << endl;
    }
}
