#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) >> vec.at(3);

    vector<int> tmp(4);


    for (int i = 0; i < 4; i++) {
    }
}



//解けなかった．
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(4);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) >> vec.at(3);
    // 4枚のカードを読み込む

    sort(vec.begin(), vec.end());
    // 昇順にソートすると、同じ数が隣り合うのでパターンが見やすくなる

    // 3+1パターン: ソート後 [x,x,x,y] または [x,y,y,y]
    bool three_one = (vec.at(0)==vec.at(1) && vec.at(1)==vec.at(2) && vec.at(2)!=vec.at(3)) ||
                     (vec.at(0)!=vec.at(1) && vec.at(1)==vec.at(2) && vec.at(2)==vec.at(3));

    // 2+2パターン: ソート後 [x,x,y,y]
    bool two_two = (vec.at(0)==vec.at(1) && vec.at(1)!=vec.at(2) && vec.at(2)==vec.at(3));

    if (three_one || two_two) {
        cout << "Yes" << endl;
        // 3+1 → 1枚加えて3+2にできる
        // 2+2 → どちらかに1枚加えて3+2にできる
    } else {
        cout << "No" << endl;
        // 4枚全部同じ / 2+1+1 / 全部バラバラ → フルハウスにできない
    }
}
*/