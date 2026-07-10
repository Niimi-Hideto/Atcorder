#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans;
    for (int i = 0; i < n; i++) {
        char c;
        long long l;
        cin >> c >> l;

        if (l > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
        ans += string(l, c);
        if (ans.size() > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
