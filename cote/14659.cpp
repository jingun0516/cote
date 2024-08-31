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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> hanjo(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> hanjo[i];
	}

	int maxV = hanjo[0];

	int answer = 0;
	int temp = 0;
	for (int i = 1; i < n; i++) {
		if (maxV > hanjo[i]) {
			temp++;
			answer = max(answer, temp);
		}
		else {
			answer = max(answer, temp);
			temp = 0;
			maxV = hanjo[i];
		}
	}
	cout << answer;

}
// https://www.acmicpc.net/problem/14659