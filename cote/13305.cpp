#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<long long> road(N - 1, 0);
	vector<long long> prices(N, 0);

	for (int i = 0; i < N-1; i++)
		cin >> road[i];

	for (int i = 0; i < N; i++)
		cin >> prices[i];

	long long cost = 0;
	long long min = prices[0];

	for (int i = 0; i < N-1; i++)		// ������ �����ҿ��� ������ ���� ����
	{
		if (prices[i] < min)
			min = prices[i];
		cost += road[i] * min;
	}
	cout << cost;
}

// https://www.acmicpc.net/problem/13305