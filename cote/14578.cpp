#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<long long> dist(n-1, 0);
	vector<long long> cost(n, 0);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	long long answer = 0;
	long long minV = cost[0];

	answer += minV * dist[0];

	for (int i = 1; i < n - 1; i++)
	{
		if (cost[i] < minV)
		{
			minV = cost[i];
		}
		answer += minV * dist[i];
		
	}
	cout << answer;

}
