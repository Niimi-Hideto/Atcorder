#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int sum = n;
    int count = 0;

    while (sum < k) {
        n += 1;
        sum += n;
        count++;
    }
    cout << count << endl;
}
