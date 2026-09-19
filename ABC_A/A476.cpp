#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int size = (int)s.size();
    if (s.at(size - 1) == 'e') {
        cout << s << 'r' << endl;
    }
    else {
        cout << s << "er" << endl;
    }
}

/* ===== 改善版（今の知識範囲での書き方）=====

   直した点
   1. s.back() で末尾の文字が取れる。size変数もキャストも要らなくなる。
      Sの長さは1以上と保証されているので空チェックも不要
      （vectorのback()と同じ。stringはfront()も使える）
   2. cout << s が2箇所に分かれていた。共通部分（s）と差分（付け足す文字）を
      見分けて1行にまとめる（ABC438 Cで指摘された「同じ処理が2箇所に分裂」と同じ形）
      ※三項演算子は両方の型を揃える必要があるので、'r'（char）ではなく
        "r"（文字列）にする。片方がchar、片方がconst char*だと通らない

int main() {
    string s;
    cin >> s;

    cout << s << (s.back() == 'e' ? "r" : "er") << endl;
}

===== ここまで ===== */
