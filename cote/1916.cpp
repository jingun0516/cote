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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<int, vector<pair<int, int>>> maps;
	vector<bool> check(N + 1, false);
	vector<int> dist(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int start, dest, cost;
		cin >> start >> dest >> cost;
		maps[start].push_back(make_pair(dest, cost));
	}
	int start, goal;
	cin >> start >> goal;

	queue<pair<int, int>> qu;

	check[start] = true;
	for (auto s : maps[start])
	{
		qu.push(make_pair(s.first, s.second));
	}

	int answer = INT_MAX;


	cout << answer;
}
