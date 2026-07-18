#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n - 1);
    vector<int> a_cop(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b.at(i);
    }
    for (int i = 0; i < n; i++) {
        a_cop.at(i) = a.at(i);
    }


    int tmp = 0;
    int ans = 30000000;
    if (a.at(0) == 0) {
        for (int i = 0; i < n - 1; i++) {
            if ((a.at(i) + a.at(i + 1)) % 2 != b.at(i)) {
                a.at(i + 1)++;
                tmp++;
            }
        }
        ans = min(ans, tmp);

        tmp = 1;
        a_cop.at(0) = 1;
        for (int i = 0; i < n - 1; i++) {
            if ((a_cop.at(i) + a_cop.at(i + 1)) % 2 != b.at(i)) {
                a_cop.at(i + 1)++;
                tmp++;
            }
        }
        ans = min(ans, tmp);
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            if ((a.at(i) + a.at(i + 1)) % 2 != b.at(i)) {
                a.at(i + 1)++;
                tmp++;
            }
        }
        ans = min(ans, tmp);

        tmp = 1;
        a_cop.at(0) = 2;
        for (int i = 0; i < n - 1; i++) {
            if ((a_cop.at(i) + a_cop.at(i + 1)) % 2 != b.at(i)) {
                a_cop.at(i + 1)++;
                tmp++;
            }
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

}

/*
// 重複をまとめた版：a_1候補{0,1}をループで回す
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n - 1; i++) cin >> b.at(i);

    int ans = 30000000;
    for (int start = 0; start <= 1; start++) {
        vector<int> a_cop(n);
        for (int i = 0; i < n; i++) a_cop.at(i) = a.at(i);

        int tmp = 0;
        if (a.at(0) != start) {
            tmp = 1;
        }
        a_cop.at(0) = start;
        for (int i = 0; i < n - 1; i++) {
            if ((a_cop.at(i) + a_cop.at(i + 1)) % 2 != b.at(i)) {
                a_cop.at(i + 1)++;
                tmp++;
            }
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
*/
