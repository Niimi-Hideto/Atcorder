#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    bool ans = true;

    for (int i = 0; i < N; i++)
    {

        if (B.at(A.at(i) - 1) == i + 1)
        {
            ans = true;
        }
        else if (B.at(A.at(i) - 1) != i + 1)
        {
            ans = false;
            break;
        }
    }

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}