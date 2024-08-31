#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> maps(n, vector<int>(n, 0));
	vector<vector<long long>> dp(n, vector<long long>(n, 0));

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (maps[y][x] == 0) continue;

			int dist = maps[y][x];

			int ny = y + dist;
			int nx = x + dist;

			if (ny < n) {
				dp[ny][x] += dp[y][x];
			}

			if (nx < n) {
				dp[y][nx] += dp[y][x];
			}
		}
	}


	cout << dp[n - 1][n - 1];
}
