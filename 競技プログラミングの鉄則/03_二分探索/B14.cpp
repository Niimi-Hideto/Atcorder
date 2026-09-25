#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a_first, a_second;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (i < n / 2) {
            a_first.push_back(tmp);
        }
        else {
            a_second.push_back(tmp);
        }
    }

    vector<long long>  b_first, b_second;
    for (int i = 0; i < (1 << n / 2); i++) {
        bitset<15> s(i);

        long long sum = 0;
        for (int j = 0; j < n / 2; j++) {
            if (s.test(j)) {
                sum += a_first.at(j);
            }
        }
        b_first.push_back(sum);
    }
    for (int i = 0; i < (1 << n / 2 + n % 2); i++) {
        bitset<15> s(i);

        long long sum = 0;
        for (int j = 0; j < n / 2 + n % 2; j++) {
            if (s.test(j)) {
                sum += a_second.at(j);
            }
        }
        b_second.push_back(sum);
    }

    sort(b_second.begin(), b_second.end());
    for (int i = 0; i < (int)b_first.size(); i++) {
        if (binary_search(b_second.begin(), b_second.end(), k - b_first.at(i))) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

/* ===== 改善点 =====
   1. 1 << n / 2 + n % 2 は、+ と / が << より先に計算されるので偶然正しい。<< は括弧で囲む
   2. 前半・後半の全列挙がほぼ同じコードの2回書きで、枚数（n/2 と n/2+n%2）を取り違えた。
      配列を渡すと選び方ごとの合計を全部返す関数にすれば、枚数は a.size() で自動で決まる

   vector<long long> all_sums(const vector<int>& a) {
       int m = a.size();
       vector<long long> res;
       for (int i = 0; i < (1 << m); i++) {
           long long sum = 0;
           for (int j = 0; j < m; j++) {
               if ((i >> j) & 1) sum += a.at(j);
           }
           res.push_back(sum);
       }
       return res;
   }

   vector<long long> b_first = all_sums(a_first), b_second = all_sums(a_second);
*/
