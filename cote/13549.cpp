#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	if (N >= K)
	{
		cout << N - K;
		return 0;
	}

	queue<pair<int, int>> qu;
	bool check[100001] = { false, };
	check[N] = true;

	qu.push(make_pair(N, 0));

	int answer = 200000;
	while (!qu.empty())
	{
		int curPos = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		check[curPos] = true;
		//cout << curPos << " " << cnt << "\n";
		if (curPos == K)
		{
			answer = min(cnt, answer);
		}

		if (curPos <= 50000 && !check[curPos * 2])
		{
			check[curPos * 2] = true;
			qu.push(make_pair(curPos * 2, cnt));
		}
		if (curPos > 0 && !check[curPos - 1])
		{
			check[curPos - 1] = true;
			qu.push(make_pair(curPos - 1, cnt + 1));
		}
		if (curPos <= 100000 && !check[curPos + 1])
		{
			check[curPos + 1] = true;
			qu.push(make_pair(curPos + 1, cnt + 1));
		}
	}
	cout << answer;

}
