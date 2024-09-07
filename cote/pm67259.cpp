#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(vector<vector<int>> board) {
	int answer = INT_MAX;

	int n = board.size() - 1;
	int dp[26][26][4];

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = INT_MAX;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		dp[0][0][i] = 0;
	}
	
	queue<pair<pair<int, int>, int>> qu;
	qu.push(make_pair(make_pair(0, 0), 0));

	while (!qu.empty()) {
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int direction = qu.front().second;

		qu.pop();

		if (x == n && y == n) continue;

		int cost = dp[x][y][direction];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > n || ny > n || board[nx][ny] == 1) continue;

			int newCost = cost + 100;

			if (!(x==0 && y==0) && direction != i) {
				newCost += 500;
			}
			
			if (dp[nx][ny][i] > newCost) {
				dp[nx][ny][i] = newCost;
				qu.push(make_pair(make_pair(nx, ny), i));
			}
		}
	}

	for (auto ans : dp[n][n])
		answer = min(answer, ans);

    return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> board = {
		{0, 0, 1, 0},
		{0, 0, 0, 0},
		{0, 1, 0, 1},
		{1, 0, 0, 0 }
	};

	cout << solution(board);
}

// https://school.programmers.co.kr/learn/courses/30/lessons/67259