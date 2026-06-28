#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }

    int count = 0;
    bool flag = true;
    int tmp = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            flag = true;
            tmp = 0;
            for (int k = i; k <= j; k++) {
                tmp += vec.at(k);
            }
            for (int k = i; k <= j; k++) {
                if (tmp % vec.at(k) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
    }
    cout << count << endl;
}
