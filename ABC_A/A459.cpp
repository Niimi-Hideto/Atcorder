#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    string hello = "HelloWorld";
    vector <string> ward(10);
    cin >> x;

    for (int i = 0; i < 10; i++) {
        if (x != i + 1) {
            ward.at(i) = hello.at(i);
        }
        else {
            continue;
        }
    }
    string final;
    for (int i = 0; i < 10; i++) {
        if (i + 1 == x) {
            continue;
        }
        else {
            final += ward.at(i);
        }
    }
    cout << final << endl;
}

// ===== 改善版（1ループ） =====
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int x;
//     string hello = "HelloWorld";  // 対象の文字列
//     string result;                // 出力用の文字列
//     cin >> x;                     // 削除する位置（1始まり）を受け取る
//
//     for (int i = 0; i < 10; i++) {
//         if (i + 1 == x) continue;         // i+1がxと一致したら飛ばす（1始まりと0始まりのズレを +1 で吸収）
//         result += hello.at(i);            // それ以外はresultに追加
//     }
//
//     cout << result << endl;       // 完成した文字列を出力
// }