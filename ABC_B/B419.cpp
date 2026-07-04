#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> vec;
    for (int i = 0; i < q; i++) {
        int que;
        cin >> que;
        if (que == 1) {
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        else if (que == 2) {
            sort(vec.begin(), vec.end());
            cout << vec.at(0) << endl;
            vec.erase(vec.begin());
        }
    }
}

