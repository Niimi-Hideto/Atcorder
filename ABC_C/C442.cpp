#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // deg.at(i) = 研究者iと利害関係にある人数
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        deg.at(a)++;
        deg.at(b)++;
    }

    for (int i = 1; i <= n; i++) {
        // 著者(i)以外の(N-1)人のうち、利害関係がある人を除いた人数
        long long avail = (long long)(n - 1) - deg.at(i);

        if (avail < 3) {
            cout << 0;
        }
        else {
            // 3人を選ぶ組み合わせの数 = avail * (avail-1) * (avail-2) / 6
            // 連続する3整数の積は必ず6で割り切れるので、割り算の余りを気にしなくていい
            long long ans = avail * (avail - 1) * (avail - 2) / 6;
            cout << ans;
        }

        if (i < n) {
            cout << " ";
        }
    }
    cout << endl;
}
