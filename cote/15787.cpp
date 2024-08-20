#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> trains(N + 1, vector<bool>(21, false));

	for (int i = 0; i < M; i++)
	{
		int order, train, seat;
		cin >> order >> train;
		switch (order)
		{
		case 1:
			cin >> seat;
			trains[train][seat] = true;
			break;
		case 2:
			cin >> seat;
			trains[train][seat] = false;
			break;
		case 3:
			for (int j = 20; j >= 1; j--)
			{
				trains[train][j] = trains[train][j - 1];
			}
			trains[train][1] = false;
			break;
		case 4:
			for (int j = 1; j < 20; j++)
			{
				trains[train][j] = trains[train][j+1];
			}
			trains[train][20] = false;
			break;
		}
	}

	set<vector<bool>> trains_set(trains.begin() + 1, trains.end());

	cout << trains_set.size();

}
