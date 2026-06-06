#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int count = 0;

    while (M > 0)
    {
        M = N % M;
        count++;
    }
    cout << count << endl;
}