#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < (int)tmp.size(); j++) {
            tmp.at(j) = toupper(tmp.at(j));
        }
        s.at(i) = tmp;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string tmp = s.at(i);
        int num = count(s.begin(), s.end(), tmp);
        ans = max(ans, num);
    }

    cout << ans << endl;
}
