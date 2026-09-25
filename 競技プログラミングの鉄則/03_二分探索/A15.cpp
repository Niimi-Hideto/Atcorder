#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    // 座標圧縮
    // 1. 値のコピーをソートする（元の a は位置を覚えておくためにそのまま残す）
    vector<int> t = a;
    sort(t.begin(), t.end());

    // 2. 重複を消す
    //    unique … 隣り合う重複を前に詰めて、使う部分の終わりの位置を返す（長さは変えない）
    //    erase  … その位置から本当の終わりまでのゴミを消す
    //    unique は隣り合う重複しか詰めないので、先に sort しておくのが必須
    t.erase(unique(t.begin(), t.end()), t.end());

    // 3. 各値が「重複のない t の中で何番目に小さいか」を二分探索で求める（1始まり）
    for (int i = 0; i < n; i++) {
        int b = lower_bound(t.begin(), t.end(), a.at(i)) - t.begin() + 1;
        cout << b << (i == n - 1 ? "\n" : " ");
    }
}

/* ===== 自分で考えた方針（pair で位置を覚える形）=====
   (値, 元の位置) の pair にしてソートし、前から「前の値と同じなら同じ番号、違えば +1」で
   番号を振って、元の位置に書き戻す。これでも O(N log N) で正しく解ける。
   本の形は t が手元に残るので、あとから来た別の値 x も同じ基準で番号に変換できるのが強み
*/
