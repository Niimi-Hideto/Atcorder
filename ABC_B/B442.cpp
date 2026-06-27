#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    int sound = 0;
    bool play = false;
    int tmp;

    for (int i = 0; i < q; i++) {
        cin >> tmp;
        if (tmp == 1) {
            sound++;
        }
        else if (tmp == 2) {
            if (sound != 0) {
                sound--;
            }
        }
        else if (tmp == 3) {
            if (play) {
                play = false;
            }
            else {
                play = true;
            }
        }

        if (sound >= 3 && play) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// play = !play; でtrue/falseを1行で反転できる（if/else不要）