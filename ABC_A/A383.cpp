#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t_tmp = 0;
    int w_sum = 0;
    int w_tmp = 0;

    vector<int> w(n);
    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t.at(i) >> w.at(i);
    }


    for (int i = 0; i < n; i++) {
        if (i == 0) {
            t_tmp = t.at(i);
            w_tmp = w.at(i);
        }
        else {
            t_tmp = t.at(i) - t.at(i - 1);
            w_sum = w_tmp - t_tmp;
            if (w_sum < 0) {
                w_sum = 0;
            }
            w_sum += w.at(i);
            w_tmp = w_sum;
        }
    }
    cout << w_tmp << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//
//     int water = 0;
//     int prev_t = 0;
//
//     for (int i = 0; i < n; i++) {
//         int t, v;
//         cin >> t >> v;
//         water = max(0, water - (t - prev_t));
//         water += v;
//         prev_t = t;
//     }
//
//     cout << water << endl;
// }
