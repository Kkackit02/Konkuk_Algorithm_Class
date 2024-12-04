#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int Q;

vector<int> ResultVector;
int main()
{

    cin >> N >> Q;
    vector<int> players(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> players[i];
    }
    for (int q = 0; q < Q; q++)
    {
        int k, newPlayer;
        cin >> k >> newPlayer;
        players.push_back(newPlayer);
        vector<vector<int>> result;
        result.resize(N + 1);

        sort(players.begin(), players.end());
        result[0].push_back(1);
        result[0].push_back(2);
        result[1].push_back(0);
        result[2].push_back(0);

        result[N].push_back(N - 1);
        result[N].push_back(N - 2);
        result[N - 1].push_back(N);
        result[N - 2].push_back(N);
        for (int i = 0; i < N + 1; i++)
        {
            vector<int> neighbors;

            for (int j = -2; j < 3; j++)
            {
                if (j == 0)
                    continue;
                if (i + j >= 0 && i + j < N + 1)
                {
                    neighbors.push_back(i + j);
                }
            }
            sort(neighbors.begin(), neighbors.end(), [&](int a, int b)
                 {
                     int diffA = abs(players[i] - players[a]);
                     int diffB = abs(players[i] - players[b]);

                     if (diffA != diffB)
                     {
                         return diffA < diffB; // 차이가 작은 값 우선
                     }
                     return result[a].size() < result[b].size(); // result size 작은 값 우선
                 });

            int idx = 0;
            while (result[i].size() < 2 && idx < neighbors.size())
            {
                if (result[neighbors[idx]].size() < 2)
                {
                    if (!result[i].empty())
                    {
                        if (result[i].front() == neighbors[idx])
                        {
                            idx++;
                        }
                    }
                    result[i].push_back(neighbors[idx]);
                    result[neighbors[idx]].push_back(i);
                }
                else
                {
                }

                idx++;
            }
        }
        int resultValue = 0;
        for (int i = 0; i < N + 1; i++)
        {

            if (!result[i].empty())
            {

                //cout << "Index " << i << ": Min Indices = (" << result[i][0] << ", " << result[i][1] << ")" << endl;
                resultValue += abs(players[i] - players[result[i][0]]);
                resultValue += abs(players[i] - players[result[i][1]]);

                // printf("%d번쨰 노드는 1번 %d와 %d의 절대차인 %d를 더합니다.\n" , i, players[i] , players[result[i][0]] , abs(players[i]-players[result[i][0]]));
                // printf("%d번쨰 노드는 2번 %d와 %d의 절대차인 %d를 더합니다.\n\n" , i, players[i] , players[result[i][1]] , abs(players[i]-players[result[i][1]]));
            }
        }
        ResultVector.push_back(resultValue/2);
        players.pop_back();
    }

    for(int i = 0; i < ResultVector.size(); i++)
    {
        printf("%d\n" , ResultVector[i]);
    }
}