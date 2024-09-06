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

	vector<int> drinks(n + 1, 0);
	int dp[10001] = { 0, };		// dp[i] 까지 최대 마실 수 있는 양

	for (int i = 1; i <= n; i++) {
		cin >> drinks[i];
	}

	dp[1] = drinks[1];
	dp[2] = dp[1] + drinks[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + drinks[i - 1] + drinks[i], dp[i - 2] + drinks[i]);
		dp[i] = max(dp[i], dp[i - 1]);		//dp[i-1] : i잔을 안 마실 경우
	}

	cout << dp[n];
}
