#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w.at(i);
    }

    int answer = 0;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (i + j + k <= v) {
                    int tmp = w.at(i) + w.at(j) + w.at(k);
                    answer = max(answer, tmp);
                }
            }
        }
    }
    cout << answer << endl;
}
