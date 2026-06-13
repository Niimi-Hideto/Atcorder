#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector <int> vec_1;
    vector <int> vec_2;
    vector <int> vec_3;
    vector <int> vec_4;


    vector <int> rvec_1;
    vector <int> rvec_2;
    vector <int> rvec_3;
    vector <int> rvec_4;

    int count_1;
    int count_2;
    int count_3;
    int count_4;


    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            cin >> vec_1.at(i);
        }



        for (int i = 0; i < k; i++) {
            cin >> vec_1.at(i);
        }

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> vec_2.at(i);
        }

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> vec_3.at(i);
        }

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> vec_4.at(i);
        }


        for (int i = 0; i < vec_1.at(0); i++) {
            if (vec_1.at(i + 1) == 2) {
                vec_2.at(1) = 1;

                count_2++;



            }




        }
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;                                      // 人数を読む

    vector<vector<int>> received(n + 1);           // 1〜N の受け取りリスト

    for (int i = 1; i <= n; i++) {                 // 人i について
        int k;
        cin >> k;                                  // 人i が送る人数
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;                              // 人i の送り先
            received.at(a).push_back(i);           // 「aはiからもらった」と記録
        }
    }

    for (int i = 1; i <= n; i++) {                 // 全員分出力
        sort(received.at(i).begin(), received.at(i).end()); // 昇順に並べる
        cout << received.at(i).size();             // 人数を出力
        for (int x : received.at(i)) {
            cout << " " << x;                      // スペース区切りで出力
        }
        cout << "\n";
    }
}

// キモ：「AがBに送った」を逆向きに「BはAからもらった」と記録し直す
// received[j].push_back(i) で「jはiからもらった」を蓄積
// 最後にソートして出力
*/
