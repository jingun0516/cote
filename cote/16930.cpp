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

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<char>> maps(N, vector<char>(M, '.'));
	vector<vector<int>> dist(N, vector<int>(M, INT_MAX));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	int startX, startY, endX, endY;
	cin >> startX >> startY >> endX >> endY;

	startX--;
	startY--;
	endX--;
	endY--;

	queue<pair<int, int>> qu;

	qu.push(make_pair(startX, startY));
	dist[startX][startY] = 0;

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		int cnt = dist[x][y];
		qu.pop();

		if (x == endX && y == endY) {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= K; j++) {
				int nx = x + dx[i] * j;
				int ny = y + dy[i] * j;

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || maps[nx][ny] == '#') break;

				if (dist[nx][ny] < cnt + 1) break;			// 더 작으면 볼 필요도 없음
				if (dist[nx][ny] == cnt + 1) continue;		// 하지만 같다면 확인을 해봐야 함
				dist[nx][ny] = cnt + 1;
				
				qu.push(make_pair(nx, ny));
			}
		}
	}

	cout << -1;



}

// https://www.acmicpc.net/problem/16930