#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    int tmp = 0;
    for (int i = 0; i < (int)a.size() - 1; i++) {
        tmp = a.at(i);
        while (1) {

        }
        if (a.at(i + 1) == tmp) {
            a.erase(a.begin() + i);
        }
    }

    cout << (int)a.size() << endl;
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;
}