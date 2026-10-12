#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int longest = 0;
    for (int i = 0; i < n; i++) {
        int a;
        char b;
        cin >> a >> b;

        if (b == 'E') {
            longest = max(longest, l - a);
        }
        else {
            longest = max(longest, a);
        }
    }

    cout << longest << endl;
}
