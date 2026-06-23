#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec1(6);
    cin >> vec1.at(0) >> vec1.at(1) >> vec1.at(2) >> vec1.at(3) >>
        vec1.at(4) >> vec1.at(5);

    vector<int> vec2(6);
    cin >> vec2.at(0) >> vec2.at(1) >> vec2.at(2) >> vec2.at(3) >>
        vec2.at(4) >> vec2.at(5);

    vector<int> vec3(6);
    cin >> vec3.at(0) >> vec3.at(1) >> vec3.at(2) >> vec3.at(3) >>
        vec3.at(4) >> vec3.at(5);


    double ans = 0;
    int tmp1_4;
    int tmp1_5;
    int tmp1_6;
    int tmp2_4;
    int tmp2_5;
    int tmp2_6;
    int tmp3_4;
    int tmp3_5;
    int tmp3_6;

    tmp1_4 = count(vec1.begin(), vec1.end(), 4);
    tmp1_5 = count(vec1.begin(), vec1.end(), 5);
    tmp1_6 = count(vec1.begin(), vec1.end(), 6);

    tmp2_4 = count(vec2.begin(), vec2.end(), 4);
    tmp2_5 = count(vec2.begin(), vec2.end(), 5);
    tmp2_6 = count(vec2.begin(), vec2.end(), 6);

    tmp3_4 = count(vec3.begin(), vec3.end(), 4);
    tmp3_5 = count(vec3.begin(), vec3.end(), 5);
    tmp3_6 = count(vec3.begin(), vec3.end(), 6);

    ans = ((tmp1_4 * tmp2_5 * tmp3_6) + (tmp1_4 * tmp2_6 * tmp3_5)
        + (tmp1_5 * tmp2_4 * tmp3_6) + (tmp1_5 * tmp2_6 * tmp3_4)
        + (tmp1_6 * tmp2_4 * tmp3_5) + (tmp1_6 * tmp2_5 * tmp3_4)) / 216.0;

    cout << ans << endl;

}

// vector版（シンプル）
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     vector<vector<int>> dice(3, vector<int>(6));
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 6; j++)
//             cin >> dice.at(i).at(j);
//
//     double ans = 0;
//     vector<int> target = {4, 5, 6};
//     // (4,5,6)の全順列を手動で列挙
//     vector<vector<int>> perms = {{4,5,6},{4,6,5},{5,4,6},{5,6,4},{6,4,5},{6,5,4}};
//     for (auto& p : perms) {
//         ans += count(dice.at(0).begin(), dice.at(0).end(), p.at(0))
//              * count(dice.at(1).begin(), dice.at(1).end(), p.at(1))
//              * count(dice.at(2).begin(), dice.at(2).end(), p.at(2));
//     }
//     cout << ans / 216.0 << endl;
// }
