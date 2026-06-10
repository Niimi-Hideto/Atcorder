// 知識足りなかった気がする
// ソートがわからんかったわ

/*

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, M;
    cin >> N >> K >> M;

    vector<vector<int>> data(N, vector<int>(2));
    for (int i = 0; i < N; i++)
    {
        cin >> data[i][0] >> data[i][1];
    }

    int sum = 0;
    int min = 0;
    int count = 0;

    vector<int> M_data;

    for (int i = 0; i < K; i++)
    {
        if (count < 2)
        {
            sum += data[i][1];
            if (data[i][1] < min)
            {
                min = data[i][1];
            }
            count++;
            M_data.push_back(data[i][0]);
        }
        else
        {
            if (min < data[i][1])
            {
                sum -= min;
                sum += data[i][1];
                min = data[i][1];
                M_data.push_back(data[i][0]);
            }
        }
    }

    if
}

*/
