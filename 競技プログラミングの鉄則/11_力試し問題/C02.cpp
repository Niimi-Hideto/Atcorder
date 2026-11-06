#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }

    int ans = a.top();
    a.pop();
    ans += a.top();

    cout << ans << endl;
}
