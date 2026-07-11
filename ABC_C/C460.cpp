#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int ans = 0;
    vector<int> use(m, 0);
    for (int i = 0; i < n; i++) {
        int k = upper_bound(b.begin(), b.end(), (a.at(i) * 2)) - b.begin() - 1;
        if (use.at(k) == 0) {
            use.at(k)++;
            ans++;
        }
        else {
            while (k > 0) {
                k--;
                if (use.at(k) == 0) {
                    use.at(k)++;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
