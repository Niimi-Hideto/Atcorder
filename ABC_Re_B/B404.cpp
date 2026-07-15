#include <bits/stdc++.h>
using namespace std;

void reverse_grid(vector<string>& vec, int n) {
    vector<string> tmp(n, string(n, 'o'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp.at(j).at(n - i - 1) = vec.at(i).at(j);
        }
    }
    for (int i = 0; i < n; i++) {
        vec.at(i) = tmp.at(i);
    }
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    vector<string> tmp_grid(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp_grid.at(i);
    }
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid.at(i);
        for (int j = 0; j < n; j++) {
            if (grid.at(i).at(j) != tmp_grid.at(i).at(j)) {
                ans++;
            }
        }
    }

    int cnt = 0;
    for (int k = 1; k <= 3; k++) {
        cnt = k;
        reverse_grid(tmp_grid, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.at(i).at(j) != tmp_grid.at(i).at(j)) {
                    cnt++;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

// 改善点1: reverse_grid → rotate_grid の方が正確（反転ではなく回転）
// 改善点2: cnt はループ内でしか使わないのでループの中で宣言する
//   for (int k = 1; k <= 3; k++) {
//       int cnt = k;
//       ...
//   }
