#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <limits.h>

using namespace std;

int N;
long long answer = LLONG_MAX;


void bt(int start, int curPos, long long dist, int cnt, vector<vector<long long>>& W, vector<bool>& check)
{
	for (int i = 0; i < N; i++)
	{
		if (curPos == i) continue;
		
		if (cnt == N - 1)
		{
			if (W[curPos][start] == 0) return;
			
			answer = min(answer, dist + W[curPos][start]);
			return;
		}

		if (!check[i] && i != start && W[curPos][i] != 0)
		{
			check[i] = true;
			bt(start, i, dist + W[curPos][i], cnt + 1, W, check);
			check[i] = false;
		}
	}

	return;
}

int main()
{
	cin >> N;
	vector<vector<long long>> W(N, vector<long long>(N, 0));
	vector<bool> check(N, false);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		bt(i, i, 0, 0, W, check);
	}
	cout << answer;
}

// https://www.acmicpc.net/problem/10971