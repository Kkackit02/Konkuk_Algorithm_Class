#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result[100000];
int degree[100000];

vector<int> players(100000); // 선수 실력 저장


void connectNode(int currentNode, int N)
{
    
        cout<<"1";
    if (degree[currentNode] == 2)
        return;
    int minV = 999999999;
    int minIdx = -1;
    for (int k = 0; k < N; k++)
    {
        if (currentNode == k)
        {
            cout<<"currentNode :"<<currentNode<<"K : "<<k<<endl;
            continue;
        }

        if(result[currentNode][0] == k)
        {
            cout<<"result[currentNode][0] :"<<result[currentNode][0]<<"K : "<<k<<endl;
            continue;
        }


        printf("%d vs %d\n", abs(players[currentNode] - players[k]), minV);
        if (abs(players[currentNode] - players[k]) < minV)
        {
            minV = abs(players[currentNode] - players[k]);
            minIdx = k;
        }
    }

    printf("check %d node , min data is %d, idx is %d\n", currentNode, minV, minIdx);
    if (degree[minIdx] == 2)
    {
        if (players[result[currentNode][0]] > minV && players[result[currentNode][1]] > minV)
        {
            if (players[result[currentNode][0]] > players[result[currentNode][1]])
            {
                result[currentNode][0] = minIdx;
                result[currentNode].push_back(minIdx);
            }
            else
            {
                result[currentNode][1] = minIdx;
                result[currentNode].push_back(minIdx);
            }
        }
        else
        {

        }
    }
    else
    {
        result[currentNode].push_back(minIdx);
        result[minIdx].push_back(currentNode);
    }
    cout<<"2";
    connectNode(minIdx, N);
}


int main()
{
    int N, Q;
    cin >> N >> Q; // N: 선수 수, Q: 훈련 프로그램 횟수


    // 초기 선수 실력 입력
    for (int i = 0; i < N; ++i)
    {
        cin >> players[i];
    }

    // Q번의 훈련 프로그램 실행
    for (int i = 0; i < Q; ++i)
    {
        int k;
        cin >> k; // 초청 선수 수 (항상 1로 가정)

        vector<int> newPlayers(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> newPlayers[j];             // 초청 선수 입력
            players.push_back(newPlayers[j]); // 초청 선수 추가
        }

        // 선수 정렬
        sort(players.begin(), players.end());


        cout<<"0";
        for(int j = 0; j < N+1; j++)
        {
            cout<<"????"<<N<<endl;
            connectNode(j, N+1);
        }
        // 정렬된 선수 출력 (디버깅용)
        cout << "After Training " << i + 1 << ":\n";
        cout << "Sorted Players: ";
        for (int p : players)
        {
            cout << p << " ";
        }
        cout << "\n";

        for (int p = 0; p < N + 1; p++)
        {
            cout << result[p][0] << ":" << result[p][1] << " " << "\n";
        }

        // 초청 선수 복원 작업 (다음 회차를 위해 제거)
        for (int j = 0; j < k; ++j)
        {
            players.pop_back();
        }
    }

    return 0;
}
