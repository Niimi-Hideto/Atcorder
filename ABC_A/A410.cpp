#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int count = 0;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (vec.at(i) >= k) {
            count++;
        }
    }
    cout << count << endl;
}
