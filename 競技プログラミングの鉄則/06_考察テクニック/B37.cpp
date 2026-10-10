#include <bits/stdc++.h>
using namespace std;

/* ===== 自分のコード（途中）=====
   ・桁ごとに 45 × p を足す方向は合っていたが、「周期がまるごと何回入るか」と「途中で終わった周期」を分けずに書いて、
     場合分けが増えて組み立てられなくなった

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    long long a = n / 10;
    long long b = n % 10;
    long long sum = 45;
    long long sum_b = 0;
    for (int i = 1; i <= b; i++) {
        sum_b += i;
    }

    int i = 0;
    long long p = 1;
    while (n > 10) {
        n /= 10;

        ans += sum * p;
        p *= 10;
    }

    for (int i = 1; i < n; i++) {
        ans += sum * p;
    }

    cout << ans << endl;
    cout << n << endl;
    cout << p << endl;
}
*/

int main() {
    long long n;
    cin >> n;

    // 0〜N の N + 1 個の数を並べて、重さ p の桁（1 の位、10 の位、…）ごとに、その桁の数字の合計を足す
    // 重さ p の桁は「0 が p 回 → 1 が p 回 → … → 9 が p 回」の長さ 10p の周期をくり返す
    long long cnt = n + 1;  // 0 を入れても桁の和は 0 なので答えは変わらない
    long long ans = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long cycle = p * 10;

        // ① 周期がまるごと入っている分：1 周期で 0〜9 が p 回ずつ → (0 + 1 + … + 9) × p = 45p
        long long full = cnt / cycle;
        ans += full * 45 * p;

        // ② 最後に途中で終わった周期（rest 個）の分
        long long rest = cnt % cycle;
        long long d = rest / p;          // 0〜d−1 は p 回ずつまるごと出ている
        ans += p * (d * (d - 1) / 2);    // (0 + 1 + … + (d − 1)) × p
        ans += d * (rest % p);           // 数字 d は途中まで、rest % p 回だけ出ている
    }

    cout << ans << endl;
}
