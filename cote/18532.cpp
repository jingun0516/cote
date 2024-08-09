#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int N, M, K, X;
	map<int, vector<int>> maps;

	cin >> N >> M >> K >> X;

	vector<bool> check(N + 1, false);
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		maps[A].push_back(B);
	}

	queue<pair<int, int>> qu;
	check[X] = true;
	qu.push(make_pair(X, 0));

	vector<int> answer;
	while (!qu.empty())
	{
		int num = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		if (cnt == K)
		{
			answer.push_back(num);
			continue;
		}

		for (auto m : maps[num])
		{
			if (!check[m])
			{
				check[m] = true;
				qu.push(make_pair(m, cnt + 1));
			}
		}
	}

	if (answer.empty())
		cout << -1;
	else
	{
		sort(answer.begin(), answer.end());
		for (auto ans : answer)
			cout << ans << "\n";
	}

}

// https://www.acmicpc.net/problem/18352