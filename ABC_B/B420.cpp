#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    vector<vector<char>> tmp(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp.at(i).at(j) = vec.at(j).at(i);
        }
    }

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int zero = count(tmp.at(i).begin(), tmp.at(i).end(), '0');
        int one = count(tmp.at(i).begin(), tmp.at(i).end(), '1');
        if (zero == 0 || one == 0) {
            ans.at(i) = 2;
        }
        else if (zero < one) {
            ans.at(i) = 0;
        }
        else if (zero > one) {
            ans.at(i) = 1;
        }
    }

    vector<int> score(n, 0);
    for (int i = 0; i < m; i++) {
        int judge = ans.at(i);
        for (int j = 0; j < n; j++) {
            if (judge == 2) {
                score.at(j)++;
            }
            else if (judge == 1) {
                if (tmp.at(i).at(j) == '1') {
                    score.at(j)++;
                }
            }
            else {
                if (tmp.at(i).at(j) == '0') {
                    score.at(j)++;
                }
            }
        }
    }
    int max_score = 0;
    for (int i = 0; i < n; i++) {
        max_score = max(max_score, score.at(i));
    }
    for (int i = 0; i < n; i++) {
        if (score.at(i) == max_score) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

// 【改善版】tmp（転置）と ans を省いて直接 vec.at(j).at(i) で参照する
// vector<int> score(n, 0);
// for (int i = 0; i < m; i++) {
//     int zero = 0, one = 0;
//     for (int j = 0; j < n; j++) {
//         if (vec.at(j).at(i) == '0') zero++;
//         else one++;
//     }
//     for (int j = 0; j < n; j++) {
//         if (zero == 0 || one == 0) score.at(j)++;
//         else if (zero < one && vec.at(j).at(i) == '0') score.at(j)++;
//         else if (zero > one && vec.at(j).at(i) == '1') score.at(j)++;
//     }
// }
// int max_score = 0;
// for (int i = 0; i < n; i++) max_score = max(max_score, score.at(i));
// for (int i = 0; i < n; i++) {
//     if (score.at(i) == max_score) cout << i + 1 << " ";
// }
// cout << endl;
