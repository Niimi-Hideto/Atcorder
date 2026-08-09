#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt = max(cnt, (int)count(vec.begin(), vec.end(), i));
    }
    cout << n - cnt << endl;
}
