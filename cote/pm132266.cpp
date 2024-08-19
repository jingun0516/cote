#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int bfs(int& start, int& destination, vector<vector<int>>& maps, vector<bool>& check)
{
	queue<pair<int, int>> qu;
	qu.push(make_pair(start, 0));

	while (!qu.empty())
	{
		int num = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		if (num == destination)
			return cnt;

		check[num] = true;

		for (auto v : maps[num]) {
			if (!check[v]) {
				qu.push(make_pair(v, cnt + 1));
				check[v] = true; 
			}
		}
	}
	return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;
	vector<vector<int>> maps(n + 1);

	for (auto r : roads)
	{
		maps[r[0]].push_back(r[1]);
		maps[r[1]].push_back(r[0]);
	}

	for (auto src : sources)
	{
		vector<bool> check(n + 1, false);

		answer.push_back(bfs(src, destination, maps, check));
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 5;
	vector<vector<int>> roads = {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}};
	vector<int> sources = { 1, 3, 5 };
	int destination = 5;

	solution(n, roads, sources, destination);

}

// https://school.programmers.co.kr/learn/courses/30/lessons/132266?language=cpp