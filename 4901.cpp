#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int Q;

int player[100000];
vector<int> result[100000];

int k;
int level;
int minV = 1234567890;

int main()
{

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> player[i];
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> k;
        cin >> player[N];

        int minV = 9999999;
        int minIdx = -1;

        for (int j = 0; j < N; j++)
        {

            for (int k = j; k >= 0; k--)
            { // 나보다 먼저 들어온 노드를 순회하며.. 가장 차이가 작은 노드 구하기
                if (abs(player[j] - player[k]) <= minV)
                {
                    minV = player[j] - player[k];
                    minIdx = k;
                    // minIdx가 가장 차이가 작은 노드의 idx
                }
            }
            if (result[minIdx].size() == 2)
            {
                if (minV < min(player[result[minIdx][0]], player[result[minIdx][1]]))
                {

                    if (result[minIdx][0] > result[minIdx][1])
                    {
                        result[minIdx][0] = j;
                    }
                    else
                    {
                        result[minIdx][1] = j;
                    }
                    result[j].push_back(minIdx);
                    // 2개인데 내가 더 효율적임 그래서 뻇기
                }
                else
                {
                    // 2개인데 나보다 더 효율적으로 되어있음..
                }
            }
            else if (result[minIdx].size() < 2)
            {
                // 2개가 아니니까 일단 가져오기
                result[minIdx].push_back(j);
                result[j].push_back(minIdx);
            }
            for (int p = 0; p < N; p++)
            {
                cout << p << ":" << result[p][0] << ":" << result[p][1] << "\n";
            }
            
            // 들어온 노드들부터 순서대로 확인할거임
            // 노드를 입력받고
            //  0번 노드부터 하나씩 그래프에 추가해나갈꺼임,
            //  노드를 추가하면 이전에 추가되어있는 노드를 순회하면서, 자신과의 차이값의 절댓값이 가장 작은 노드를 구한다.
            //  만약 그 노드가 이미 연결된 노드가 2개 이하라면 자신과 연결하고,
            //  만약 이전 노드가 이미 연결된 노드가 2개 이상이라면, 그 값 중 가장 작은 값과 비교해서 내가 더 작으면 빼앗는다
            //  내가 더 크면 포기하고, 그 다음으로 차이값이 작은 노드에서 확인
            //  이를 계속해서 반복하는데, 모든 노드가 추가 되었으면, 남아있는.. 연결된 노드가 2개 이하인 노드들로 다시 이 작업을 수행한다.
            //  모든 노드의 연결된 노드가 2가 되는 순간 종료
        }
        
        int sum_result = 0;
        for (int j = 0; j < N; j++)
        {
            sum_result += result[j][0] + result[j][1];
        }
        sum_result /= 2;
        cout << "\n\n"
             << sum_result << "\n";
    }
}