#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    map<int, vector<int>> maps;
    map<int, vector<int>> dist;
    vector<int> check(n+1, false);
    
    for (auto e : edge)
    {
        maps[e[0]].push_back(e[1]);
        maps[e[1]].push_back(e[0]);
    }
    queue<pair<int, int>> qu;
    qu.push(make_pair(1, 0));
    check[1] = true;

    int maxV = 0;
    while (!qu.empty())
    {
        int start = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();
        for (auto m : maps[start])
        {
            if (!check[m])
            {
                check[m] = true;
                qu.push(make_pair(m, cnt + 1));
                dist[cnt+1].push_back(m);
                maxV = max(maxV, cnt + 1);
            }
        }
    }
    answer = dist[maxV].size();

    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, edge);
}